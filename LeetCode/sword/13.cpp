class Solution {
public:
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    int cnt(int num) {
        int ans = 0;
        while(num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int movingCount(int m, int n, int k) {
        int ans = 1;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        visit[0][0] = true;
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for(int i = 0; i < 4; ++i) {
                int tmp_x = x + dir[i][0];
                int tmp_y = y + dir[i][1];
                if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n && visit[tmp_x][tmp_y] == false) {
                    visit[tmp_x][tmp_y] = true;
                    if(cnt(tmp_x) + cnt(tmp_y) <= k) {
                        q.push({tmp_x, tmp_y});
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};