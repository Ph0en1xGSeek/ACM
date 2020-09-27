class Solution {
public:
	int dir[4][2] = {1,0,-1,0,0,1,0,-1};
	vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
		queue<pair<int, int>> q;
		int row = matrix.size();
		if(row == 0) {
			return matrix;
		}
		int col = matrix[0].size();
		if(col == 0) {
			return matrix;
		}
		vector<vector<bool>> vis(row, vector<bool>(col, false));
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(matrix[i][j] == 0) {
					vis[i][j] = true;
					q.push({i, j});
				}
			}
		}
		int step = 0;
		while(!q.empty()) {
			++step;
			int q_size = q.size();
			for(int i = 0; i < q_size; ++i) {
				auto cur = q.front();
				q.pop();
				int x = cur.first;
				int y = cur.second;
				for(int j = 0; j < 4; ++j) {
					int new_x = x + dir[j][0];
					int new_y = y + dir[j][1];
					if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col) {
						if(!vis[new_x][new_y]) {
							vis[new_x][new_y] = true;
							matrix[new_x][new_y] = step;
							q.push({new_x, new_y});
						}
					}
				}
			}
		}
		return matrix;
	}
};
