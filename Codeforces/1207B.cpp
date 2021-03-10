#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int arr[55][55];
int dir[4][3][2] = {{{0, 1}, {1, 0}, {1, 1}},
                    {{0, -1}, {1, 0}, {1, -1}},
                    {{0, 1}, {-1, 0}, {-1, 1}},
                    {{0, -1}, {-1, 0}, {-1, -1}}};

int check_and_change(int x, int y) {
    int i;
    bool flag;
    for(i = 0; i < 4; ++i) {
        flag = true;
        for(int j = 0; j < 3; ++j) {
            if(arr[x + dir[i][j][0]][y + dir[i][j][1]] == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(int j = 0; j < 3; ++j) {
                arr[x + dir[i][j][0]][y + dir[i][j][1]] = -1;
            }
            break;
        }
    }
    return i;
}

int main() {
    int n, m;
    vector<pair<int, int>> dot;
    while(~scanf("%d%d", &n, &m)) {
        memset(arr, 0, sizeof(arr));
        dot.clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n && cnt >= 0; ++i) {
            for(int j = 1; j <= m && cnt >= 0; ++j) {
                if(arr[i][j] == 1) {
                    int ret = check_and_change(i, j);
                    if(ret == 0) {
                        dot.push_back({i, j});
                    }else if(ret == 1) {
                        dot.push_back({i, j-1});
                    }else if(ret == 2) {
                        dot.push_back({i-1, j});
                    }else if(ret == 3) {
                        dot.push_back({i-1, j-1});
                    }else {
                        cnt = -1;
                    }
                }
            }
        }
        if(cnt == -1) {
            printf("-1\n");
        }else {
            cnt = dot.size();
            printf("%d\n", cnt);
            for(int i = 0; i < cnt; ++i) {
                printf("%d %d\n", dot[i].first, dot[i].second);
            }
        }
    }
    return 0;
}