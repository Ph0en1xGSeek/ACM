class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		int flag1 = 0, flag2 = 0;
		int sz_row = matrix.size();
		if(sz_row == 0) {
			return;
		}
		int sz_col = matrix[0].size();
		if(sz_col == 0) {
			return;
		}
		for(int i = 0; i < sz_col; ++i) {
			if(matrix[0][i] == 0) {
				flag1 = 1;
				break;
			}
        } 
        for(int j = 0; j < sz_row; ++j) {
            if(matrix[j][0] == 0) {
                flag2 = 1;
                break;
            }
        }
        for(int i = 1; i < sz_row; ++i) {
            for(int j = 1; j < sz_col; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < sz_row; ++i) {
            for(int j = 1; j < sz_col; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag1 == 1) {
            for(int i = 0; i < sz_col; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(flag2 == 1) {
            for(int i = 0; i < sz_row; ++i) {
                matrix[i][0] = 0;
            }
        }
	}
};
