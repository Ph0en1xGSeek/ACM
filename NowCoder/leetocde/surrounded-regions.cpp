class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int szx = board.size();
        if(szx == 0) {
            return;
        }
        int szy = board[0].size();
        if(szy == 0) {
            return;
        }
        for(int i = 0; i < szx; ++i) {
            if(board[i][0] == 'O') {
                dfs(board, szx, szy, i, 0);
            }
            if(board[i][szy-1] == 'O') {
                dfs(board, szx, szy, i, szy-1);
            }
        }
        
        for(int j = 0; j < szy; ++j) {
            if(board[0][j] == 'O') {
                dfs(board, szx, szy, 0, j);
            }
            if(board[szx-1][j] == 'O') {
                dfs(board, szx, szy, szx-1, j);
            }
        }
        for(int i = 0; i < szx; ++i) {
            for(int j = 0; j < szy; ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }else if(board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int szx, int szy, int x, int y) {
        board[x][y] = '*';
        for(int i = 0; i < 4; ++i) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if(newx >= 0 && newx < szx && newy >= 0 && newy < szy && board[newx][newy] == 'O') {
                dfs(board, szx, szy, newx, newy);
            }
        }
    }
private:
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};
};