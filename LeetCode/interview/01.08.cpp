class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = true;
        bool col = true;
        int size_row = matrix.size();
        if(size_row == 0) {
            return;
        }
        int size_col = matrix[0].size();
        if(size_col == 0) {
            return;
        }
        for(int i = 0; i < size_col; ++i) {
            if(matrix[0][i] == 0) {
                row = false;
                break;
            }
        }
        for(int i = 0; i < size_row; ++i) {
            if(matrix[i][0] == 0) {
                col = false;
                break;
            }
        }
        for(int i = 1; i < size_row; ++i) {
            for(int j = 1; j < size_col; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < size_row; ++i) {
            for(int j = 1; j < size_col; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(!row) {
            for(int i = 0; i < size_col; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(!col) {
            for(int i = 0; i < size_row; ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};