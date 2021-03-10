class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; ++i) {
            for(int j = 2; j < i; ++j) {
                int tmp_j = max(dp[j], j);
                int tmp_ij = max(dp[i-j], i-j);
                dp[i] = max(dp[i], tmp_j * tmp_ij);
            }
        }
        return dp[n];
    }
};