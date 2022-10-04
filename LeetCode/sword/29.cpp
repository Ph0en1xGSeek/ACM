class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if (row == 0) {
            return result;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return result;
        }
        result.reserve(row * col);
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            if (top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
            }
            if (left < right) {
                for (int i = bottom; i > top; --i) {
                    result.push_back(matrix[i][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return result;
    }
};