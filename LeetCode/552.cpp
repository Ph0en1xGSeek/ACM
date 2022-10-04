class Solution {
public:
    const int mod = 1000000007;
    int checkRecord(int n) {
        int dp[2][3][2] = {0};
        int cur = 1;
        dp[cur][0][1] = 1;
        dp[cur][1][0] = 1;
        dp[cur][0][0] = 1;
        for(int i = 2; i <= n; ++i) {
            cur = 1 - cur;
            dp[cur][0][0] = ((dp[1- cur][0][0] + dp[1 - cur][1][0]) % mod + dp[1 - cur][2][0]) % mod;
            dp[cur][0][1] = (((dp[cur][0][0] + dp[1- cur][0][1]) % mod + dp[1 - cur][1][1]) % mod + dp[1 - cur][2][1]) % mod;
            dp[cur][1][0] = dp[1 - cur][0][0];
            dp[cur][1][1] = dp[1 - cur][0][1];
            dp[cur][2][0] = dp[1 - cur][1][0];
            dp[cur][2][1] = dp[1 - cur][1][1];
        }
        int ans = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 2; ++j) {
                ans = (ans + dp[cur][i][j]) % mod;
            }
        }
        return ans;
    }
};