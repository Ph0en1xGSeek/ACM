class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int size_x = matrix.size();
        int size_y = 0;
        if(size_x != 0) {
            size_y = matrix[0].size();
        }
        arr.resize(size_x + 1, vector<long long>(size_y + 1, 0));
        for(int i = 0; i < size_x; ++i) {
            for(int j = 0; j < size_y; ++j ) {
                arr[i+1][j+1] = arr[i][j+1] + arr[i+1][j] - arr[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr[row2+1][col2+1] + arr[row1][col1] - arr[row2+1][col1] - arr[row1][col2+1];
    }
private:
    vector<vector<long long>> arr;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */