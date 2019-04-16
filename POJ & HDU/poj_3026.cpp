#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#define M 55
#define M_ROBOT 105

using namespace std;

struct node{
    int x;
    int y;
    int step;
    node(int a, int b, int c){
        x = a;
        y = b;
        step = c;
    }
    node(){
        x = 0;
        y = 0;
        step = 0;
    }
}robots[M_ROBOT];

struct queueEdge{
    int num;
    int v;
    queueEdge(){
        num = 0;
        v = 0;
    }
    queueEdge(to, len){
        num = to;
        v = len;
    }
};

char mp[M][M];
int arr[M_ROBOT][M_ROBOT];
bool vis[M][M];
int n, m, num;

void bfs(int start){
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    robots[start].step = 0;
    q.push(robots[start]);
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        vis[cur.x][cur.y] = true;
        char tmp = mp[cur.x][cur.y];
        if(tmp != '#' && tmp != ' '){
            arr[start][(int)tmp] = cur.step;
        }
        if(mp[cur.x-1][cur.y] != '#' && !vis[cur.x-1][cur.y])
            q.push(node(cur.x-1, cur.y, cur.step+1));
        if(mp[cur.x+1][cur.y] != '#' && !vis[cur.x+1][cur.y])
            q.push(node(cur.x+1, cur.y, cur.step+1));
        if(mp[cur.x][cur.y-1] != '#' && !vis[cur.x][cur.y-1])
            q.push(node(cur.x, cur.y-1, cur.step+1));
        if(mp[cur.x][cur.y+1] != '#' && !vis[cur.x][cur.y+1])
            q.push(node(cur.x, cur.y+1, cur.step+1));
    }
}

int prim(int start){
    int ans = 0;
    memset(vis, false, sizeof(vis));
    priority_queue<queueEdge> q;
    q.push(queueEdge(start, 0));
    for(int k = 0; k < num; k++){
        do{
            node cur = q.top();
            q.pop();
        }while(vis[cur.num]);
        vis[cur.num] = true;
        ans += vis.v;
        for(int i = 0; i < num; i++){
            if(!vis[i])
                q.push(queueEdge(i, arr[cur.num][i]));
        }

    }
    return ans;
}

int main(){
    int ca;
    scanf("%d", &ca);
    while(ca--){
        num = 0;
        scanf("%d%d", &m, &n);
        getchar();
        for(int i = 0; i < n; i++){
            gets(mp[i]);
            for(int j = 0; j < m; j++){
                if(mp[i][j] == 'A' || mp[i][j] == 'S'){
                    mp[i][j] = num;
                    robots[num].x = i;
                    robots[num].y = j;
                    num++;
                }
            }
        }
        for(int i = 0; i < num; i++){
            bfs(i);
        }
        int ans = prim(0);
        printf("%d\n", ans);
    }
    return 0;
}
