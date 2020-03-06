class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		if(query_row < 0 || query_glass > query_row) {
			return -1.0;
		}
		vector<double> dp(query_row + 1, 0.0);
		dp[0] = poured;
		for(int i = 1; i <= query_row; ++i) {
			for(int j = i; j >= 0; --j) {
				if(dp[j] > 1.0)
					dp[j] = (dp[j] - 1) / 2;
				else
					dp[j] = 0;
				if(j > 0 && dp[j-1] > 1.0)
					dp[j] += (dp[j-1] - 1) / 2;
			}
		}
		return dp[query_glass] > 1 ? 1: dp[query_glass];
	}
};