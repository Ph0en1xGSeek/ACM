#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int mp[45][15];
bool grid[405][405];
char in[15];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int cnt;
bool vis[405];
int link[405];
int num;

bool dfs(int x){
    for(int y = 0; y < num; y++){
        if(grid[x][y] && !vis[y]){
            vis[y] = true;
            if(link[y] == -1 || dfs(link[y])){
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}

void search(){
    memset(link, -1, sizeof(link));
    for(int i = 0; i < num; i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)){
            cnt++;
        }
    }
}

int main(){
    int ca;
    scanf("%d", &ca);
    while(ca--){
        memset(mp, -1, sizeof(mp));
        memset(grid, 0, sizeof(grid));
        num = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%s", in+1);
            for(int j = 1; j <= m; j++){
                if(in[j] == '*'){
                    mp[i][j] = num++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(mp[i][j] >= 0)
                    for(int k = 0; k < 4; k++){
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if(mp[x][y] >= 0){
                            grid[mp[i][j]][mp[x][y]] = true;
                        }
                    }
            }
        }

        cnt = 0;
        search();
        printf("%d\n", num - cnt/2);
    }
    return 0;
}