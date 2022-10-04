class NumMatrix {
public:
    vector<vector<int>> matrix;

    int row;

    int col;

    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            vector<int> row_vec(col);
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) {
                    row_vec[j] = matrix[i][j];
                } else if (i == 0) {
                    row_vec[j] = row_vec[j - 1] + matrix[i][j];
                } else if (j == 0) {
                    row_vec[j] = (this -> matrix)[i - 1][j] + matrix[i][j];
                } else {
                    row_vec[j] = (this -> matrix)[i - 1][j] + matrix[i][j]
                                        - (this -> matrix)[i - 1][j - 1] + row_vec[j - 1];
                }
            }
            this -> matrix.push_back(row_vec);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return this -> matrix[row2][col2];
        } else if (row1 == 0) {
            return this -> matrix[row2][col2] - this -> matrix[row2][col1 - 1];
        } else if (col1 == 0) {
            return this -> matrix[row2][col2] - this -> matrix[row1 - 1][col2];
        } else {
            return this -> matrix[row2][col2] + this -> matrix[row1 - 1][col1 - 1] - this -> matrix[row1 - 1][col2] - this -> matrix[row2][col1 - 1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */