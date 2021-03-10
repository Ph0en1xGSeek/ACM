#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int v, next;
}edge[80010];

int head[205];
int color[205];
int cnt;

int vis[205], linker[205];

void addedge(int a, int b)
{
    edge[cnt].v = b;
    edge[cnt].next = head[a];
    head[a] = cnt++;
}

bool bfs()
{
    int now, next;
    queue<int>  q;
    q.push(1);
    memset(color, -1, sizeof(color));
    color[1] = 1;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            next = edge[i].v;
            if(color[next] == -1)
            {
                color[next] = 1-color[now];
                q.push(next);
            }
            else if(color[next] == color[now])
                return false;
        }
    }
    return true;
}

int match(int now)
{
    for(int i = head[now]; i != -1; i = edge[i].next)
    {
        int next = edge[i].v;
        if(!vis[next])
        {
            vis[next] = 1;
            if(linker[next] == -1 || match(linker[next]))
            {
                linker[next] = now;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;
    int a, b;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(linker, -1, sizeof(linker));
        for(int i = 0 ;i < m; i++)
        {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        if(!bfs())
        {
            printf("No\n");
            continue;
        }
        int ans = 0;
        for(int i = 1 ; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            ans += match(i);
        }
        printf("%d\n", ans/2);
    }
    return 0;
}
