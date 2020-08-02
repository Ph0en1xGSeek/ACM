class Solution {
public:
	bool exist(vector<vector<char>> &board, string word) {
		row = board.size();
		if(row == 0) {
			return false;
		}
		col = board[0].size();
		if(col == 0) {
			return false;
		}
		vector<vector<bool>> vis(row, vector<bool>(col, false));
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(dfs(board, vis, i, j, word, 0)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	int row;
	int col;
	bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int x, int y, string &word, int pos) {

		if(board[x][y] == word[pos]) {
            if(pos == word.size() - 1) {
                return true;
            }
			vis[x][y] = true;
			for(int i = 0; i < 4; ++i) {
				int nex_x = x + dir[i][0];
				int nex_y = y + dir[i][1];
				if(nex_x >= 0 && nex_x < row && nex_y >= 0 && nex_y < col && vis[nex_x][nex_y] == false) {
					if(dfs(board, vis, nex_x, nex_y, word, pos + 1)) {
						return true;
					}
				}
			}
			vis[x][y] = false;
		}
		return false;
	}
	int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
};
