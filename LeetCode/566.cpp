class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
		int row = nums.size();
		if(row == 0) {
			return nums;
		}
		int col = nums[0].size();
		if(col == 0) {
			return nums;
		}
		if(r * c != row * col) {
			return nums;
		}
		vector<vector<int>> ret(r, vector<int>(c));
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				int tmp = i * col + j;
				ret[tmp / c][tmp % c] = nums[i][j];
			}
		}
		return ret;
	}
};
