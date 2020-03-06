class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+2, vector<int>(n+2, 0)));
		++i, ++j;
		int cur = 0;
		dp[cur][i][j] = 1;
        int sum = 0;
		for(int k = 1; k <= N; ++k) {
			cur = 1 - cur;
			for(int x = 0; x <= m+1; ++x) {
				for(int y = 0; y <= n+1; ++y) {
					dp[cur][x][y] = 0;
				}
			}
			for(int x = 1; x <= m; ++x) {
				sum = (sum + dp[1-cur][x][1]) % mod;
				sum = (sum + dp[1-cur][x][n]) % mod;
			}
			for(int y = 1; y <= n; ++y) {
				sum = (sum + dp[1-cur][1][y]) % mod;
				sum = (sum + dp[1-cur][m][y]) % mod;
			}
			for(int x = 1; x <= m; ++x) {
				for(int y = 1; y <= n; ++y) {
					for(int d = 0; d < 4; ++d) {
						int from_x = x + dir[d][0];
						int from_y = y + dir[d][1];
                        if(from_x >= 1 && from_x <= m && from_y >= 1 && from_y <= n) {
                            dp[cur][x][y] = (dp[cur][x][y] + dp[1-cur][from_x][from_y]) % mod;
                        }
					}
				}
			}
		}
		return sum;
	}
private:
	int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
	const int mod = 1000000007;
};