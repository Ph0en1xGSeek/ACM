class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        board[i][j] = '*';
        for(int d = 0; d < 4; d++){
            int next_i = i + dir[d][0];
            int next_j = j + dir[d][1];
            if(next_i >= 0 && next_j >= 0 && next_i < n && next_j < m && board[next_i][next_j] == 'O'){
                dfs(board, next_i, next_j, n, m);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0){
            return;
        }
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0, n, m);
            }
            if(board[i][m-1] == 'O'){
                dfs(board, i, m-1, n, m);
            }
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O'){
                dfs(board, 0, j, n, m);
            }
            if(board[n-1][j] == 'O'){
                dfs(board, n-1, j, n, m);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};