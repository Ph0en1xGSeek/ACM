class Solution {
public:
	int kInversePairs(int n, int k) {
		if(k == 0) {
			return 1;
		}
		vector<vector<int>> dp(2, vector<int>(k+1, 0));
		dp[0][0] = 1;
        int cur = 0;
		for(int i = 2; i <= n; ++i) {
            cur = 1 - cur;
            dp[cur][0] = 1;
            for(int j = 1; j <= k; ++j) {
                dp[cur][j] = (dp[cur][j-1] + dp[1-cur][j]) % mod;
                if(j - i >= 0) {
                    dp[cur][j] = (dp[cur][j] - dp[1-cur][j-i] + mod) % mod;
                }
            }
		}
		return dp[cur][k];
	}
private:
	int mod = 1000000007;
};