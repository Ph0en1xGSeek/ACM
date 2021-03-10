class Solution {
private:
    vector<vector<int>> dp;
    int size_x;
    int size_y;
    
public:
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        if(dp[x][y] > 0)
            return dp[x][y];
        int mx = 0;
        if(x-1 >= 0 && matrix[x-1][y] < matrix[x][y]) {
            mx = max(mx, dfs(matrix, x-1, y));
        }
        if(x + 1 < size_x && matrix[x+1][y] < matrix[x][y]) {
            mx = max(mx, dfs(matrix, x+1, y));
        }
        if(y - 1 >= 0 && matrix[x][y-1] < matrix[x][y]) {
            mx = max(mx, dfs(matrix, x, y-1));
        }
        if(y + 1 < size_y && matrix[x][y+1] < matrix[x][y]) {
            mx = max(mx, dfs(matrix, x, y+1));
        }
        dp[x][y] = ++mx;
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        size_x = matrix.size();
        if(size_x == 0)
            return 0;
        size_y = matrix[0].size();
        if(size_y == 0) 
            return 0;

        dp.resize(size_x, vector<int>(size_y, -1));
        int ans = 0;
        for(int i = 0; i < size_x; ++i) {
            for(int j = 0; j < size_y; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};