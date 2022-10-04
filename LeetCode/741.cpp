class Solution {
public:
	int cherryPickup(vector<vector<int>> &grid) {
		int n = grid.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		dp[0][0] = grid[0][0];
		for(int k = 1; k < (n << 1) - 1; ++k) {
			for(int i = min(n-1, k); i >= 0 && i >= k - n + 1; --i) {
				for(int j = min(n-1, k); j >= 0 && j >= k - n + 1; --j) {
					if(grid[i][k-i] == -1 || grid[j][k-j] == -1) {
						dp[i][j] = -1;
                        continue;
					}
					if(i > 0) {
						dp[i][j] = max(dp[i][j], dp[i-1][j]);
					}
					if(j > 0) {
						dp[i][j] = max(dp[i][j], dp[i][j-1]);
					}
					if(i > 0 && j > 0) {
						dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
					}
					if(dp[i][j] == -1) {
						continue;
					}
					if(i == j) {
						dp[i][j] += grid[i][k-i];
					}else {
						dp[i][j] += grid[i][k-i] + grid[j][k-j];
					}
				}
			}
		}
		return max(dp[n-1][n-1], 0);
	}
};