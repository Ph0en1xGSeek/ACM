class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int sz1 = text1.size();
		int sz2 = text2.size();
		if(sz1 == 0 || sz2 == 0) {
			return 0;
		}
		vector<vector<int>> dp(2, vector<int>(sz2+1, 0));
		int cur = 0;
		for(int i = 1; i <= sz1; ++i) {
			cur = 1 - cur;
			for(int j = 1; j <= sz2; ++j) {
				if(text1[i-1] == text2[j-1]) {
					dp[cur][j] = dp[1 - cur][j-1] + 1;
				}else {
					dp[cur][j] = max(dp[1 - cur][j], dp[cur][j-1]);
				}
			}
		}
		return dp[cur][sz2];
	}
};
