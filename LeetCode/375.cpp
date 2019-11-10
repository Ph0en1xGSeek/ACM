class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2);
        for(int i = 0 ;i < n+2; ++i) {
            dp[i].resize(n+2, 0);
        }
        for(int l = n-1; l >= 1; --l) {
            for(int r = l + 1; r <= n; ++r) {
                dp[l][r] = INT_MAX;
                for(int i = l; i <= r; ++i) {
                    dp[l][r] = min(dp[l][r], i + max(dp[l][i-1], dp[i+1][r]));
                }
            }
        }
        return dp[1][n];
    }
};