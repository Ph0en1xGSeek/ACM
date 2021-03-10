class Solution {
public:
    void printMatrix(vector<vector<int>> &matrix, int start, int row, int col, vector<int> &ans, int &cnt) {
        int height = row - (start << 1);
        int width = col - (start << 1);
        for(int i = 0; i < width; ++i) {
            ans[cnt++] = matrix[start][start + i];
        }
        if(height > 1) {
            for(int i = 0; i < height - 1; ++i) {
                ans[cnt++] = matrix[start + 1 + i][start + width - 1];
            }
        }
        if(height > 1 && width > 1) {
            for(int i = width - 2; i >= 0; --i) {
                ans[cnt++] = matrix[start + height - 1][start + i];
            }
        }
        if(width > 1 && height > 2) {
            for(int i = height - 2; i > 0; --i) {
                ans[cnt++] = matrix[start + i][start];
            }
        }
    }
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int row = matrix.size();
        if(row == 0) {
            return ans;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return ans;
        }
        ans.resize(row * col);
        int cnt = 0;
        for(int i = 0; (i << 1) < row && (i << 1) < col; ++i) {
            printMatrix(matrix, i, row, col, ans, cnt);
        }
        return ans;
    }
};