class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int mx = INT_MIN;
        vector<int> ans(4);
        int col_from;
        vector<int> accu(col, 0); 
        int sum;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                accu[j] = 0;
            }
            for(int j = i; j < row; ++j) {
                sum = 0;
                for(int k = 0; k < col; ++k) {
                    accu[k] += matrix[j][k];
                    if(sum > 0) {
                        sum += accu[k];
                    }else {
                        col_from = k;
                        sum = accu[k];
                    }
                    if(sum > mx) {
                        mx = sum;
                        ans[0] = i;
                        ans[1] = col_from;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        return ans;
    }
};