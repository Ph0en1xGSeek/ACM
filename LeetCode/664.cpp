class Solution {
public:
	int strangePrinter(string s) {
		int size = s.size();
        if(size == 0) {
            return 0;
        }
		vector<vector<int>> dp(size, vector<int>(size, 0));
		for(int i = size-1; i >= 0; --i) {
			for(int j = i; j < size; ++j) {
				if(i == j) {
					dp[i][j] = 1;
				}else {
                    dp[i][j] = dp[i+1][j] + 1;
                }
				for(int k = i+1; k <= j; ++k) {
					if(s[i] == s[k])
						dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
				}
			}
		}
		return dp[0][size-1];
	}
};
