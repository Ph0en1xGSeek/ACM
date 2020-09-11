class Solution {
public:
    vector<int> accu;
    int bound;
    Solution(vector<int>& w) {
        accu = w;
        int size = w.size();
        for(int i = 1; i < size; ++i) {
            accu[i] += accu[i-1];
        }
        bound = accu[size - 1];
    }
    
    int pickIndex() {
        int r = rand() % bound + 1;
        int pos = lower_bound(accu.begin(), accu.end(), r) - accu.begin();
        return pos;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */



// alias method


struct Node {
    int id1;
    int id2;
    double prob;
    Node() : id1(-1), id2(-1), prob(0.0) {}
    Node(int id1_, double prob_): id1(id1_), id2(-1), prob(prob_) {}
    bool operator<(const Node &other) const {
        if(prob == other.prob) {
            return id1 < other.id1;
        }
        return prob < other.prob;
    }
};

class Solution {
public:
    vector<Node> samples;
    Solution(vector<int>& w) {
        int size = w.size();
        double sum = accumulate(w.begin(), w.end(), 0);
        set<Node> st;
        for(int i = 0; i < size; ++i) {
            Node node = Node(i, w[i] * size / sum);
            st.insert(node);
        }
        while(!st.empty()) {
            if(st.size() == 1) {
                Node sample = *st.begin();
                sample.id2 = sample.id1;
                samples.push_back(sample);
                break;
            }
            Node small = *st.begin();
            Node large = *st.rbegin();
            st.erase(small);
            st.erase(large);
            small.id2 = large.id1;
            large.prob -= 1 - small.prob;
            st.insert(large);
            samples.push_back(small);
        }
    }
    
    int pickIndex() {
        int pos = rand() % samples.size();
        double p = rand() * 1.0 / RAND_MAX;
        if(p <= samples[pos].prob) {
            return samples[pos].id1;
        }else {
            return samples[pos].id2;
        }
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */