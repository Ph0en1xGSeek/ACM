class Solution {
public:
	int findPairs(vector<int> &nums, int k) {
		int sum = 0;
		int size = nums.size();
		if(size == 0 || k < 0) {
			return 0;
		}
		unordered_map<int, int>mp;
		for(int i = 0; i < size; ++i) {
			++mp[nums[i]];
		}
		for(auto item: mp) {
			if(mp.find(item.first + k) != mp.end()) {
				if(k == 0) {
					if(item.second > 1) {
                        sum += 1;
                    }
				}else {
					sum += 1;
				}
			}
		}
		return sum;
	}
};