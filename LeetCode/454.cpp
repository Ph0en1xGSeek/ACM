class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sz = A.size();
        if(sz == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                ++mp[A[i] + B[j]];
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                if(mp.find(-C[i] - D[j]) != mp.end()) {
                    ans += mp[-(C[i] + D[j])];
                }
            }
        }
        return ans;
    }
};