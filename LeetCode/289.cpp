class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if(rows == 0) {
            return;
        }
        int columns = board[0].size();
        if(columns == 0) {
            return;
        }
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < columns; ++j) {
                int sum = getNumNeighbor(board, rows, columns, i, j);
                if((board[i][j] & 1) && (sum == 2) || (sum == 3)) {
                    board[i][j] |= (1<<1);
                }else if((board[i][j] ^ 1) && (sum == 3)) {
                    board[i][j] |= (1<<1);
                }
            }
        }
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < columns; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
    
    int getNumNeighbor(vector<vector<int>> &board, int rows, int columns, int x, int y) {
        int sum = 0;
        for(int i = x-1; i <= x+1; ++i) {
            for(int j = y-1; j <= y+1; ++j) {
                if(i == x && j == y) {
                    continue;
                }
                if(i >= 0 && j >= 0 && i < rows && j < columns) {
                    if((board[i][j] & 1) != 0) {
                        ++sum;
                    }
                }
            }
        }
        return sum;
    }
};