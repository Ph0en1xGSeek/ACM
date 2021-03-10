#include <bits/stdc++.h>

using namespace std;


int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
vector<string> mp;

bool visited[101][101][1025];

struct node{
    int x, y, key, step;
    node(int _x, int _y, int _key, int _step) {
        x = _x;
        y = _y;
        key = _key;
        step = _step;
    }
};


int main()
{
    int ans;
    while(cin >> n >> m) {
        unordered_set<char> key_set;
        mp.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> mp[i];
        }
        int x = -1, y = -1;
        for(int i = 0; i < n && x < 0; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mp[i][j] == '2') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        queue<node> q;
        q.push(node(x, y, 0, 0));
        visited[x][y][0] = true;
        bool found = false;
        while(!q.empty() && !found) {
            node cur = q.front();
            q.pop();
            int key = cur.key;
            if(mp[cur.x][cur.y] >= 'a' && mp[cur.x][cur.y] <= 'z') {
                key |= (1 << (mp[cur.x][cur.y] - 'a'));
            }
            for(int j = 0; j < 4; ++j) {
                int next_x = cur.x + dir[j][0];
                int next_y = cur.y + dir[j][1];
                if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && mp[next_x][next_y] != '0' && visited[next_x][next_y][key] == false) {
                    if(mp[next_x][next_y] >= 'A' && mp[next_x][next_y] <= 'Z') {
                        if((key & (1 << (mp[next_x][next_y] - 'A'))) == 0) {
                            continue;
                        }
                    }
                    if(mp[next_x][next_y] == '3') {
                        ans = cur.step + 1;
                        found = true;
                        break;
                    }
                    visited[next_x][next_y][key] = true;
                    q.push(node(next_x, next_y, key, cur.step+1));
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
