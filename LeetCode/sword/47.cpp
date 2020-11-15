class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(col + 1, 0));
        int cur = 0;
        for(int i = 0; i < row; ++i) {
            cur = 1 - cur;
            for(int j = 0; j < col; ++j) {
                dp[cur][j + 1] = max(dp[cur][j], dp[1 - cur][j + 1]) + grid[i][j];
            }
        }
        return dp[cur][col];
    }
};