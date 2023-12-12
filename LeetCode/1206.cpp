constexpr int MAX_LEVEL = 32;
const double P_FACTOR = 0.25;

struct SkiplistNode {
	int val;
	vector<SkiplistNode *> forward;
	SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {
	}
};


class Skiplist {
private:
	SkiplistNode *head;
	int level;
	mt19937 gen{random_device{}()};
	uniform_real_distribution<double> dis;

public:
	Skiplist() : head(new SkiplistNode(-1)), level(0), dis(0, 1) {
	}

	bool search(int target) {
		SkiplistNode *cur = this -> head;
		for (int i = level - 1; i >= 0; --i) {
			while (cur -> forward[i] != nullptr && cur -> forward[i] -> val < target) {
				cur = cur -> forward[i];
			}
		}
		cur = cur -> forward[0];

		if (cur != nullptr && cur -> val == target) {
			return true;
		}
		return false;
	}

	void add(int num) {
		// 超出当前的level的，直接接在head后面
		vector<SkiplistNode *> update(MAX_LEVEL, head);
		SkiplistNode *cur = this -> head;
		for (int i = level - 1; i >= 0; --i) {
			while (cur -> forward[i] != nullptr && cur -> forward[i] -> val < num) {
				cur = cur -> forward[i];
			}
			update[i] = cur;
		}
		int _level = randomLevel();
		level = max(_level, level);
		SkiplistNode *newNode = new SkiplistNode(num, _level);
		for (int i = 0; i < _level; ++i) {
			newNode -> forward[i] = update[i] -> forward[i];
			update[i] -> forward[i] = newNode;
		}
	}
	
	bool erase(int num) {
		vector<SkiplistNode *> update(MAX_LEVEL, nullptr);
		SkiplistNode *cur = this -> head;
		for (int i = level - 1; i >= 0; --i) {
			while (cur -> forward[i] != nullptr && cur -> forward[i] -> val < num) {
				cur = cur -> forward[i];
			}
			update[i] = cur;
		}
		cur = cur -> forward[0];
		if (cur == nullptr || cur -> val != num) {
			return false;
		}
		for (int i = 0; i < level; ++i) {
			if (update[i] -> forward[i] != cur) {
				break;
			}
			update[i] -> forward[i] = cur -> forward[i];
		}
		delete cur;
		while (level > 1 && head -> forward[level - 1] == nullptr) {
			--level;
		}
		return true;
	}

	int randomLevel() {
		int _level = 1;
		while (dis(gen) < P_FACTOR && _level < MAX_LEVEL) {
			++_level;
		}
		return _level;
	}
};