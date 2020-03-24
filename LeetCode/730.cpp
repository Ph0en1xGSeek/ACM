class Solution {
public:
	int countPalindromicSubsequences(string S) {
		int size = S.size();
		if(size == 0) {
			return 0;
		}
		vector<vector<int>> dp(size, vector<int> (size, 0));
		for(int i = size - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for(int j = i + 1; j < size; ++j) {
				if(S[i] == S[j]) {
					dp[i][j] = dp[i+1][j-1] * 2 % mod;
					int l = i + 1;
					int r = j - 1;
					while(l <= r && S[i] != S[l])
						++l;
					while(l <= r && S[j] != S[r])
						--r;
					if(l > r) {
						dp[i][j] = (dp[i][j] + 2) % mod;
					}else if(l == r) {
						dp[i][j] = (dp[i][j] + 1) % mod;
					}else {
						dp[i][j] = (dp[i][j] - dp[l+1][r-1] + mod) % mod;
					}
				}else {
					dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) % mod - dp[i+1][j-1] + mod) % mod;
				}
			}
		}
		return dp[0][size-1];
	}
private:
	const int mod = 1000000007;
};