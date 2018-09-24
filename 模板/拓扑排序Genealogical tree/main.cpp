#include <iostream>
#define M 105
#include <cstring>
#include <stdio.h>

using namespace std;

int g[M][M];
int vis[M];
int topo[M], top, n, m;

int dfs(int u)
{
    vis[u] = -1;
    for(int v = 1; v <= n; v++)
    {
        if(g[u][v])
        {
            if(vis[v] < 0)
                return false;
            else if(!vis[v] && !dfs(v))
                return false;
        }
    }
    vis[u] = 1;
    topo[--top] = u;
    return true;
}

bool toposort()
{
    top = n;
    memset(vis, 0, sizeof(vis));
    for(int i = n; i >=1; i--)
    {
        if(!vis[i] && !dfs(i))
            return false;
    }

    return true;
}


int main()
{
    int to;
    memset(g, 0, sizeof(g));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            scanf("%d", &to);
            if(to == 0)
                break;
            g[i][to] = 1;
        }
    }
    toposort();
    for(int i = 0; i < n-1; i++)
        printf("%d ", topo[i]);
    printf("%d\n", topo[n-1]);
    return 0;
}
