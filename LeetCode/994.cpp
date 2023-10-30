class Solution {
public:

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> dis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    ++cnt;
                    dis[i][j] = 0;
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++cnt;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            --cnt;
            ans = max(ans, dis[x][y]);
            for (int i = 0; i < 4; ++i) {
                int next_x = x + dir[i][0];
                int next_y = y + dir[i][1];
                if (next_x >= 0 && next_x < n &&
                    next_y >= 0 && next_y < m &&
                    grid[next_x][next_y] == 1 && dis[next_x][next_y] < 0) {
                    dis[next_x][next_y] = dis[x][y] + 1;
                    q.push({next_x, next_y});
                } 
            }
        }
        return cnt == 0 ? ans : -1;
    }
};