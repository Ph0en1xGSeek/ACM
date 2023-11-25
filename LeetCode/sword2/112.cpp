class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> degree(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int next_x = i + dir[k][0];
                    int next_y = j + dir[k][1];
                    if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n &&
                    matrix[next_x][next_y] < matrix[i][j]) {
                        --degree[i][j];
                    }
                }
                if (degree[i][j] == 0) {
                    q.emplace(i, j);
                    dis[i][j] = 1;
                }
            }
        }
        
        int ans = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int next_x = x + dir[k][0];
                int next_y = y + dir[k][1];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n &&
                matrix[next_x][next_y] > matrix[x][y]) {
                    ++degree[next_x][next_y];
                    if (degree[next_x][next_y] == 0) {
                        q.emplace(next_x, next_y);
                        dis[next_x][next_y] = max(dis[next_x][next_y], dis[x][y] + 1);
                    }
                    ans = max(ans, dis[next_x][next_y]);
                }
                
            }
        }
        return ans;
    }
};