#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 500

using namespace std;

bool grid[M][M];
bool vis[M];
int n, k;
int cnt;
int link[M];

bool dfs(int x){
    for(int i = 1; i <= n; i++){
        if(grid[x][i] && !vis[i]){
            vis[i] = true;
            if(link[i] == -1 || dfs(link[i]) == true){
                link[i] = x;
                return true;
            }
        }
    }
    return false;
}

void search(){
    for(int i = 1; i <= n; i++){
        memset(vis, false, sizeof(vis));
        if(dfs(i))
            cnt++;
    }
}

int main(){
    int x, y;
    while(~scanf("%d%d", &n, &k)){
        memset(link, -1, sizeof(link));
        memset(grid, false, sizeof(grid));
        for(int i = 0; i < k; i++){
            scanf("%d%d", &x, &y);
            grid[x][y] = true;
        }
        cnt = 0;
        search();
        printf("%d\n", cnt);
    }
    return 0;
}
