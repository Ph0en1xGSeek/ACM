class Solution {
public:
    Solution(int n_rows, int n_cols) {
        this->n_rows = n_rows;
        this->n_cols = n_cols;
        this->remain = n_rows * n_cols;
    }
    
    vector<int> flip() {
        int pos = random() % remain;
        --remain;
        int real_pos = mp.find(pos) != mp.end()? mp[pos]: pos;
        mp[pos] = mp.find(remain) != mp.end()? mp[remain]: remain;
        return {real_pos / this->n_cols, real_pos % this->n_cols};
    }
    
    void reset() {
        mp.clear();
        remain = this->n_rows * this->n_cols;
    }

    int n_rows;
    int n_cols;
    unordered_map<int, int> mp;
    int remain;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */