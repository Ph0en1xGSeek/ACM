class Solution {
private:
	int rows;
	int cols;
	int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
	void dfs(vector<vector<int>> &grid, int x, int y, int &cnt) {
		++cnt;
        grid[x][y] = 0;
		for(int i = 0; i < 4; ++i) {
			int new_x = x + dir[i][0];
			int new_y = y + dir[i][1];
			if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && grid[new_x][new_y] == 1) {
				dfs(grid, new_x, new_y, cnt);
			}
		}
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		rows = grid.size();
		if(rows == 0) {
			return 0;
		}
		cols = grid[0].size();
		if(cols == 0) {
			return 0;
		}
		int ans = 0;
		int cnt;
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				if(grid[i][j] == 1) {
					cnt = 0;
					dfs(grid, i, j, cnt);
					ans = max(ans, cnt);
				}
			}
		}
		return ans;
	}
};