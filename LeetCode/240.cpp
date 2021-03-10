class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        if(m == 0) {
            return false;
        }
        int x = 0, y = m-1;
        while(x < n && y >= 0) {
            if(matrix[x][y] == target) {
                return true;
            }else if(matrix[x][y] < target) {
                ++x;
            }else {
                --y;
            }
        }
        return false;
    }
};