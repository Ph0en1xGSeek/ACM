#include <iostream>
#include <stdio.h>
#include <algorithm>
#define NUM 1000004
#define INF 0x3fffffff

using namespace std;

string mp[101];
int shortest_path[101][101] = {0};
int path[NUM] = {0};

int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            cin >> mp[i];
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &path[i]);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                shortest_path[i+1][j+1] = mp[i][j] == '1'? 1: 0x3fffffff;
            }
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    shortest_path[i][j] = min(shortest_path[i][k] + shortest_path[k][j], shortest_path[i][j]);
                }
            }
        }
        int last = 0;
        int cnt = 1;
        for(int i = 1; i <= m-1; ++i) {
            if(shortest_path[path[last]][path[i+1]] == i + 1 - last && path[last] != path[i+1])
                path[i] = -1;
            else {
                last = i;
                ++cnt;
            }
        }
        printf("%d\n", cnt);
        for(int i = 1; i <= m; ++i) {
            if(path[i] != -1) {
                printf("%d ", path[i]);
            }
        }
        printf("\n");
    }    
    return 0;
}