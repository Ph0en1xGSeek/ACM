struct Node {
    int id1;
    int id2;
    double prob;
    Node() : id1(-1), id2(-1), prob(0.0) {}
    Node(int _id1, double _prob) : id1(_id1), id2(-1), prob(_prob) {}

    bool operator<(const Node &other) const {
        if (prob == other.prob) {
            return id1 < other.id1;
        }
        return prob < other.prob;
    }
};

class Solution {
private:
    // 别名表
    vector<Node> samples; 
public:
    Solution(vector<int>& w) {
        int size = w.size();
        double sum = accumulate(w.begin(), w.end(), 0);
        set<Node> st;
        for (int i = 0; i < size; ++i) {
            Node node = Node(i, w[i] / sum * size);
            st.insert(node);
        }
        while (!st.empty()) {
            if (st.size() == 1) {
                Node sample = *st.begin();
                sample.id2 = sample.id1;
                samples.push_back(sample);
                break;
            }
            Node first = *st.begin();
            Node last = *st.rbegin();
            st.erase(first);
            st.erase(last);
            first.id2 = last.id1;
            last.prob -= (1 - first.prob);
            st.insert(last);
            samples.push_back(first);
        }
    }
    
    int pickIndex() {
        int pos = rand() % samples.size();
        double p = rand() * 1.0 / RAND_MAX;
        if (p <= samples[pos].prob) {
            return samples[pos].id1;
        } else {
            return samples[pos].id2;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */