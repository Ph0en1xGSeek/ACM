class Solution {
public:
	int numDistinct(string S, string T) {
		int len_s = S.size();
		int len_t = T.size();
		if(len_t == 0) {
			return 1;
		}else if(len_s == 0) {
			return 0;
		}
		vector<vector<int>> dp(2, vector<int>(len_s + 1, 1));
		int cur = 1;
		for(int i = 1; i <= len_t; ++i) {
		    dp[cur][0] = 0;
			for(int j = 1; j <= len_s; ++j) {
				dp[cur][j] = dp[cur][j-1] + (T[i-1] == S[j-1] ? dp[1 - cur][j-1] : 0);
			}
			cur = 1 - cur;
		}
		return dp[1-cur][len_s];
	}
};
