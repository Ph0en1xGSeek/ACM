class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        if(sz <= 2) {
            return 0;
        }
        int cnt = 0;
        vector<unordered_map<long long, int>> dp(sz);
        for(int i = 1; i < sz; ++i) {
            for(int j = 0; j < i; ++j) {
                long long diff = (long long) A[i] - (long long)A[j];
                dp[i][diff] += (dp[j][diff] + 1);
                cnt += dp[j][diff];
            }
        }
        return cnt;
    } 
};