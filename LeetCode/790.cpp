class Solution {
public:
	int numTilings(int N) {
		if(N == 0) {
			return 1;
		}else if(N == 1) {
			return 1;
		}else if(N == 2) {
			return 2;
		}
		vector<int> dp(N+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
		for(int i = 3; i <= N; ++i) {
			dp[i] = ((dp[i-1] * 2) % mod + dp[i-3]) % mod;
		}
		return dp[N];
	}
private:
	const int mod = 1000000007;
};