#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct state {
    int p_x;
    int p_y;
    int b_x;
    int b_y;
    state(int _p_x, int _p_y, int _b_x, int _b_y): p_x(_p_x), p_y(_p_y), b_x(_b_x), b_y(_b_y){}
};

int main() {
    const int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};
    bool visit[8][8][8][8];
    int row, col;
    int p_x, p_y, b_x, b_y, t_x, t_y;
    while(cin >> row >> col) {
        vector<string> arr(row);
        for(int i = 0; i < row; ++i) {
            cin >> arr[i];
        }
        memset(visit, false, sizeof(visit));
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(arr[i][j] == '*') {
                    b_x = i;
                    b_y = j;
                }else if(arr[i][j] == 'X') {
                    p_x = i;
                    p_y = j;
                }else if(arr[i][j] == '@') {
                    t_x = i;
                    t_y = j;
                }
            }
        }
        queue<state> q;
        q.push(state(p_x, p_y, b_x, b_y));
        int cnt = 0;
        visit[p_x][p_y][b_x][b_y] = true;
        bool find = false;
        while(!q.empty()) {
            ++cnt;
            int size = q.size();
            while(size--) {
                auto cur = q.front();
                int cur_px = cur.p_x, cur_py = cur.p_y, cur_bx = cur.b_x, cur_by = cur.b_y;
                q.pop();
                if(cur_bx == t_x && cur_by == t_y) {
                    find = true;
                    break;
                }
                for(int i = 0; i < 4; ++i) {
                    int new_x = cur_px + dir[i][0];
                    int new_y = cur_py + dir[i][1];
                    if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && arr[new_x][new_y] != '#') {
                        if(cur_bx == new_x && cur_by == new_y) {
                            int new_bx = cur_bx + dir[i][0];
                            int new_by = cur_by + dir[i][1];
                            if(new_bx >= 0 && new_bx < row && new_by >= 0 && new_by < col && arr[new_bx][new_by] != '#') {
                                if(!visit[new_x][new_y][new_bx][new_by]) {
                                    q.push(state(new_x, new_y, new_bx, new_by));
                                    visit[new_x][new_y][new_bx][new_by] = true;
                                }
                            }
                        }else {
                            if(!visit[new_x][new_y][cur_bx][cur_by]) {
                                q.push(state(new_x, new_y, cur_bx, cur_by));
                                visit[new_x][new_y][cur_bx][cur_by] = true;
                            }
                        }
                    }
                }
            }
        }
        if(!find) {
            cout << -1 << endl;
        }else {
            cout << cnt << endl;
        }
    }
    return 0;
}