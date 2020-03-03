class Solution {
public:
	int minDistance(string word1, string word2) {
		int sz1 = word1.size();
		int sz2 = word2.size();
		if(sz1 == 0) {
			return sz2;
		}else if(sz2 == 0) {
			return sz1;
		}
		vector<vector<int>> dp(2, vector<int>(sz2 + 1, 0));
		for(int i = 0; i <= sz2; ++i) {
			dp[0][i] = i;
		}
		int cur = 0;
		for(int i = 1; i <= sz1; ++i) {
			cur = 1 - cur;
			dp[cur][0] = i;
			for(int j = 1; j <= sz2; ++j) {
				if(word1[i-1] == word2[j-1]) {
					dp[cur][j] = dp[1-cur][j-1];
				}else {
					dp[cur][j] = min(dp[1-cur][j], dp[cur][j-1]);
					dp[cur][j] = min(dp[cur][j], dp[1-cur][j-1]);
					++dp[cur][j];
				}
			}
		}
		return dp[cur][sz2];
	}
};