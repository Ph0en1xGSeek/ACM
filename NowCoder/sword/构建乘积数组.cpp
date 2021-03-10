class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sz = A.size();
        if(sz == 0) {
            return vector<int>(0);
        }
        vector<int> res(sz, 1);
        for(int i = 1; i < sz; ++i) {
            res[i] = res[i-1] * A[i-1];
        }
        int tmp = A.back();
        for(int i = sz-2; i >= 0; --i) {
            res[i] *= tmp;
            tmp *= A[i];
        }
        return res;
    }
};