#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

char g[1005][1005];
int vis[1005][1005];
int n, m;
int x1, y1;
int x2, y2;
int ans;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

struct node
{
    int x, y, cnt;
    node(int xx = 0, int yy = 0, int cc = 0):x(xx),y(yy),cnt(cc){};
    friend bool operator <(const node &a, const node &b)
    {
        return a.cnt > b.cnt;
    }///·´Ð´ Ð¡¶¥¶Ñ
};

void bfs()
{
    priority_queue<node> q;
    while(!q.empty()) q.pop();
    q.push(node(x1, y1, 0));
    node tmp;
    while(!q.empty())
    {
        tmp = q.top();
        q.pop();
        if(tmp.x == x2 && tmp.y == y2)
        {
            ans = tmp.cnt;
            return;
        }
        for(int k = 0; k < 4; k++)
        {
            int t;
            int i = tmp.x+dir[k][0];
            int j = tmp.y+dir[k][1];
            if(i > n || i < 1 || j > m || j < 1 || vis[i][j])
                continue;
            if(g[i][j] == 'X')
                t = tmp.cnt;
            else
                t = tmp.cnt+1;
            q.push(node(i, j, t));
            vis[i][j] = 1;
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) && (n&&m))
    {
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", g[i]+1);
        }
        ans = -1;
        scanf("%d%d", &x1, &y1);
        scanf("%d%d", &x2, &y2);
        bfs();
        printf("%d\n", ans);
    }
    return 0;
}
