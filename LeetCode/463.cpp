class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        if(cols == 0) {
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    cnt += 4;
                    if(i + 1 < rows && grid[i+1][j] == 1) {
                        cnt -= 2;
                    }
                    if(j + 1 < cols && grid[i][j + 1] == 1) {
                        cnt -= 2;
                    }
                }
            }
        }
        return cnt;
    } 
};