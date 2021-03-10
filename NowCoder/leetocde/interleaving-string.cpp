class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int sz1 = s1.size();
		int sz2 = s2.size();
		int sz3 = s3.size();
		if(sz3 != sz1 + sz2) {
			return false;
		}
		vector<vector<int>> dp(sz1 + 1, vector<int> (sz2 + 1));
		dp[0][0] = true;
		for(int i = 1; i <= sz1; ++i) {
			dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
		}
		for(int i = 1; i <= sz2; ++i) {
			dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
		}
		for(int i = 1; i <= sz1; ++i) {
			for(int j = 1; j <= sz2; ++j) {
				dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
			}
		}
		return dp[sz1][sz2];
	}
};