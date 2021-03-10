class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        if(row == 0) {
            return M;
        }
        int col = M[0].size();
        if(col == 0) {
            return M;
        }
        int sum, cnt;
        vector<vector<int>> ret(row, vector<int>(col));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cnt = 1;
                sum = M[i][j];
                for(int d = 0; d < 8; ++d) {
                    int new_x = i + dir[d][0];
                    int new_y = j + dir[d][1];
                    if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col) {
                        sum += M[new_x][new_y];
                        ++cnt;
                    }
                    ret[i][j] = sum / cnt;
                }
            }
        }
        return ret;
    }
private:
    int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
};