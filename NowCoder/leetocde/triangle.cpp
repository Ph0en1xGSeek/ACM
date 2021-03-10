class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int rows = triangle.size();
		if(rows == 0) {
			return 0;
		}
		vector<int> dp(triangle[rows-1].begin(), triangle[rows-1].end());
		for(int i = rows-2; i >= 0; --i) {
			for(int j = 0; j <= i; ++j) {
				dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
			}
		}
		return dp[0];
    }
};