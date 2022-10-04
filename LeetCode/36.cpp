class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool col[9][10];
        bool row[9][10];
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row[i][board[i][j]-'0'])
                        return false;
                    row[i][board[i][j] - '0'] = true;
                    if(col[j][board[i][j]-'0'])
                        return false;
                    col[j][board[i][j]-'0'] = true;
                }
            }
        }

        bool isExisted[10];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                memset(isExisted, false, sizeof(isExisted));
                for(int ii = 0; ii < 3; ii++){
                    for(int jj = 0; jj < 3; jj++){
                        if(board[i*3+ii][j*3+jj] != '.'){
                            if(isExisted[board[i*3+ii][j*3+jj]-'0']){
                                return false;
                            }
                            isExisted[board[i*3+ii][j*3+jj]-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};