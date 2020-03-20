class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int size1 = s1.size();
		int size2 = s2.size();
		int ans = 0;
		vector<vector<int>> dp(2, vector<int>(size2 + 1, 0));
		for(int i = 1; i <= size2; ++i) {
			dp[0][i] = dp[0][i-1] + s2[i-1];
		}
		int cur = 0;
		for(int i = 1; i <= size1; ++i) {
			cur = 1 - cur;
			dp[cur][0] = dp[1 - cur][0] + s1[i-1];
			for(int j = 1; j <= size2; ++j) {
				if(s1[i-1] == s2[j-1]) {
					dp[cur][j] = dp[1-cur][j-1];
				}else {
					dp[cur][j] = dp[cur][j-1] + s2[j-1];
					dp[cur][j] = min(dp[cur][j], dp[1-cur][j] + s1[i-1]);
				}
			}
		}
		return dp[cur][size2];
	}
};
