class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ret = 0;
        int sz_r = heightMap.size();
        if(sz_r == 0) {
            return 0;
        }
        int sz_c = heightMap[0].size();
        if(sz_c == 0) {
            return 0;
        }
        
        vector<vector<bool>> visited(sz_r, vector<bool>(sz_c, false));
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > q;
        for(int i = 0; i < sz_r; ++i) {
            for(int j = 0; j < sz_c; ++j) {
                if(i == 0 || i == sz_r - 1 || j == 0 || j == sz_c - 1) {
                    q.push({heightMap[i][j], i * sz_c + j});
                    visited[i][j] = true;
                }
            }
        }
        
        int max_height = 1;
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();
            max_height = max(max_height, cur.first);
            int x = cur.second / sz_c;
            int y = cur.second % sz_c;
            for(int i = 0; i < 4; ++i) {
                int new_x = x + dir[i][0];
                int new_y = y + dir[i][1];
                if(new_x >= 0 && new_x < sz_r && new_y >= 0 && new_y < sz_c && visited[new_x][new_y] == false) {
                    q.push({heightMap[new_x][new_y], new_x * sz_c + new_y});
                    visited[new_x][new_y] = true;
                    if(heightMap[new_x][new_y] < max_height) {
                        ret += (max_height - heightMap[new_x][new_y]);
                    }
                }
            }
        }
        return ret;
    }

private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};