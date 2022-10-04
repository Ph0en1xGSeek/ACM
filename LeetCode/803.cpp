class Solution {
private:
	int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int size = hits.size();
        int row = grid.size();
        int col = grid[0].size();
        if(size == 0) {
            return vector<int>();
        }
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        vector<int> ans(size);
        for(int i = 0; i < size; ++i) {
            if(grid[hits[i][0]][hits[i][1]] == 1) {
                grid[hits[i][0]][hits[i][1]] = 0;
            }else {
                hits[i][0] = hits[i][1] = -1;
            }
        }
        
        queue<pair<int, int>> q;
        for(int i = 0; i < col; ++i) {
            if(grid[0][i] == 1) {
                q.push({0, i});
                vis[0][i] = true;
            }
        }

        while(!q.empty()) {
            auto cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nex_x = x + dir[i][0];
                int nex_y = y + dir[i][1];
                if(nex_x >= 0 && nex_x < row && nex_y >= 0 && nex_y < col) {
                    if(grid[nex_x][nex_y] == 1 && vis[nex_x][nex_y] == false) {
                        vis[nex_x][nex_y] = true;
                        q.push({nex_x, nex_y});
                    }
                }
            }
        }
        for(int i = size - 1; i >= 0; --i) {
            if(hits[i][0] == -1) {
                ans[i] = 0;
                continue;
            }
            bool flag = false;
            for(int j = 0; j < 4; ++j) {
                int pos_x = hits[i][0] + dir[j][0];
                int pos_y = hits[i][1] + dir[j][1];
                if(pos_x < 0) {
                    flag = true;
                    break;
                }
                if(pos_x >= 0 && pos_x < row && pos_y >= 0 && pos_y < col && vis[pos_x][pos_y]) {
                    flag = true;
                    break;
                }
            }
            grid[hits[i][0]][hits[i][1]] = 1;
            if(!flag) {
                continue;
            }
            int cnt = 0;
            vis[hits[i][0]][hits[i][1]] = true;
            q.push({hits[i][0], hits[i][1]});
            while(!q.empty()) {
                auto cur = q.front();
                int x = cur.first;
                int y = cur.second;
                q.pop();
                for(int j = 0; j < 4; ++j) {
                    int nex_x = x + dir[j][0];
                    int nex_y = y + dir[j][1];
                    if(nex_x >= 0 && nex_x < row && nex_y >= 0 && nex_y < col) {
                        if(grid[nex_x][nex_y] == 1 && vis[nex_x][nex_y] == false) {
                            vis[nex_x][nex_y] = true;
                            q.push({nex_x, nex_y});
                            ++cnt;
                        }
                    }
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
