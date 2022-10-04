class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return false;
        }
        int x = 0;
        int y = col - 1;
        while(x < row && y >= 0) {
            if(matrix[x][y] > target) {
                --y;
            }else if(matrix[x][y] < target) {
                ++x;
            }else {
                break;
            }
        }
        if(x < row && y >= 0) {
            return true;
        }else {
            return false;
        }
    }
};