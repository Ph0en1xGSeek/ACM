class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i < (n >> 1); ++i) {
            res[i << 1] = res[i];
            res[(i << 1) | 1] = res[i] + 1;
        }
        if (n & 1) {
            res[n - 1] = res[n >> 1];
            res[n] = res[n >> 1] + 1;
        } else {
            res[n] = res[n >> 1];
        }
        
        return res;
    }
};