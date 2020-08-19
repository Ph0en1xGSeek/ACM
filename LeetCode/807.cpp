class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int row = grid.size();
	int col = grid[0].size();
	vector<int> row_max(row, 0);
	vector<int> col_max(col, 0);
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			row_max[i] = max(row_max[i], grid[i][j]);
			col_max[j] = max(col_max[j], grid[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col;++j) {
			ans += min(row_max[i], col_max[j]) - grid[i][j];
		}
	}
	return ans;
    }
};
