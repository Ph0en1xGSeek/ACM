class Solution {
public:
	int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1, -1,1,-1,-1};
	vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
		int row = board.size();
		int col = board[0].size();
		int x = click[0];
		int y = click[1];
		if(board[x][y] == 'M') {
			board[x][y] = 'X';
			return board;
		}
        vector<vector<bool>> visit(row, vector<bool>(col, false));
		queue<pair<int, int>> q;
		q.push({x, y});
        visit[x][y] = true;
		while(!q.empty()) {
			auto cur = q.front();
			x = cur.first;
			y = cur.second;
			q.pop();
			int cnt = 0;
			for(int i = 0; i < 8; ++i) {
				int new_x = x + dir[i][0];
				int new_y = y + dir[i][1];
				if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col) {
					if(board[new_x][new_y] == 'M') {
						++cnt;
					}
				}
			}

			if(cnt > 0) {
				board[x][y] = '0' + cnt;
			}else {
                board[x][y] = 'B';
                for(int i = 0; i < 8; ++i) {
                    int new_x = x + dir[i][0];
                    int new_y = y + dir[i][1];
                    if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && !visit[new_x][new_y]) {
                        visit[new_x][new_y] = true;
                        if(board[new_x][new_y] == 'E') {
                            q.push({new_x, new_y});
                        }
                    }
                }
            }
		}
		return board;
	}
};
