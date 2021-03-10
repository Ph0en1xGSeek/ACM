class Solution {
public:
    int numSquares(int n) {
        const int MX = 0x7fffffff;
        vector<int> dp(n+1, MX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};