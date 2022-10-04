class Solution {
public:

    bool dfs(vector<vector<char> >& board, bool row[][9], bool col[][9], bool grid[][3][9], int i, int j){
        if(i == 9) return true;
        if(board[i][j] != '.'){
            int ii = i;
            int jj = j + 1;
            if(jj == 9){
                jj = 0;
                ii++;
            }
            return dfs(board, row, col, grid, ii, jj);
        }
        for(int ins = 0; ins < 9; ins++){
            if(row[i][ins] == false && col[j][ins] == false && grid[i/3][j/3][ins] == false){
                board[i][j] = (char)(ins + '0' + 1);
                row[i][ins] = true;
                col[j][ins] = true;
                grid[i/3][j/3][ins] = true;
                int ii = i;
                int jj = j + 1;
                if(jj == 9){
                    jj = 0;
                    ii++;
                }
                if(dfs(board, row, col, grid, ii, jj))
                    return true;
                row[i][ins] = false;
                col[j][ins] = false;
                grid[i/3][j/3][ins] = false;
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board){
        bool row[9][9];
        bool col[9][9];
        bool grid[3][3][9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[i][j] != '.'){
                    int tmp = board[i][j] - '0' - 1;
                    row[i][tmp] = true;
                    col[j][tmp] = true;
                    grid[i/3][j/3][tmp] = true;
                }
            }
        }
        dfs(board, row, col, grid, 0, 0);
    }

};
