class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int row = board.size();
        if(row == 0) {
            return 0;
        }
        int col = board[0].size();
        if(col == 0) {
            return 0;
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 'X') {
                    if((i > 0 && board[i-1][j] == 'X') || (j > 0 && board[i][j-1] == 'X'))
                        continue;
                    else
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};