class Solution {
public:
    bool dfs(char *matrix, char *str, int r, int c, int pos) {
        if(pos == str_sz) {
            return true;
        }
        if(r < 0 || r >= num_rows || c < 0 || c >= num_cols) {
            return false;
        }
        if(matrix[r * num_cols + c] != str[pos] || flags[r * num_cols + c] == true) {
            return false;
        }
        flags[r * num_cols + c] = true;
        for(int i = 0; i < 4; ++i) {
            if(dfs(matrix, str, r + dir[i][0], c + dir[i][1], pos + 1)) {
                return true;
            }
        }
        flags[r * num_cols + c] = false;
        return false;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        num_rows = rows;
        num_cols = cols;
        if(rows == 0 || cols == 0) {
            return false;
        }
        flags.resize(num_rows * num_cols, false);
        str_sz = strlen(str);
        if(str_sz == 0) {
            return true;
        }
        for(int i = 0; i < num_rows; ++i) {
            for(int j = 0; j < num_cols; ++j) {
                if(dfs(matrix, str, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int num_rows;
    int num_cols;
    int str_sz;
    vector<bool> flags;
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};
};