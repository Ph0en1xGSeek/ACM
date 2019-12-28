class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        int m = matrix.size();
        if(m == 0) {
            return ret;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return ret;
        }
        vector<vector<int>> pac = vector<vector<int>>(m, vector<int>(n, false));
        vector<vector<int>> atl = vector<vector<int>>(m, vector<int>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            q.push({i, 0});
            pac[i][0] = true;
        }
        for(int i = 0; i < n; ++i) {
            q.push({0, i});
            pac[0][i] = true;
        }
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for(int i = 0; i < 4; ++i) {
                int new_x = x + dir[i][0];
                int new_y = y + dir[i][1];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] >= matrix[x][y] && !pac[new_x][new_y]) {
                    q.push({new_x, new_y});
                    pac[new_x][new_y] = true;
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            q.push({i, n-1});
            atl[i][n-1] = true;
        }
        for(int i = 0; i < n; ++i) {
            q.push({m-1, i});
            atl[m-1][i] = true;
        }
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for(int i = 0; i < 4; ++i) {
                int new_x = x + dir[i][0];
                int new_y = y + dir[i][1];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && matrix[new_x][new_y] >= matrix[x][y] && !atl[new_x][new_y]) {
                    q.push({new_x, new_y});
                    atl[new_x][new_y] = true;
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pac[i][j] && atl[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
};