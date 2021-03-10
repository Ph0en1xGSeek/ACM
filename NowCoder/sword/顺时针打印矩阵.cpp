class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int row = matrix.size();
        if(row == 0) {
            return ret;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return ret;
        }
        for(int i = 0; i * 2 < row && i * 2 < col; ++i) {
            printCircle(i, matrix, row, col, ret);
        }
        return ret;
    }
    
    void printCircle(int start, vector<vector<int>> &matrix, int row, int col, vector<int> &ret) {
        int height = row - 2 * start;
        int width = col - 2 * start;
        for(int i = 0; i < width; ++i) {
            ret.push_back(matrix[start][start + i]);
        }
        if(height > 1) {
            for(int i = 1; i < height; ++i) {
                ret.push_back(matrix[start + i][start + width - 1]);
            }
        }
        if(width > 1 && height > 1) {
            for(int i = width - 2; i >= 0; --i) {
                ret.push_back(matrix[start + height - 1][start + i]);
            }
        }
        if(height > 2 && width > 1) {
            for(int i = height - 2; i >= 1; --i) {
                ret.push_back(matrix[start + i][start]);
            }
        }
    }
};