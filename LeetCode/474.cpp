class Solution {
public:
	int findMaxForm(vector<string> &strs, int m, int n) {
		int zero = 0, one = 0;
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(string str: strs) {
			one = 0, zero = 0;
			for(int i = 0; i < str.size(); ++i) {
				if(str[i] == '0') ++zero;
                else ++one; 
			}
			for(int i = m; i >= zero; --i) {
				for(int j = n; j >= one; --j) {
					dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
				}
			}
		}
		return dp[m][n];
	}
};