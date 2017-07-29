#include <iostream>
#include <stdio.h>
#include <string.h>
#define M 1501

using namespace std;

struct node
{
    int v;
    int next;
}e[M<<3];
int head[M], vis[M], dp[M][2];
int cnt, root;

void addedge(int u, int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
    e[cnt].v = u;
    e[cnt].next = head[v];
    head[v] = cnt++;
}

void dfs(int u)
{
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i = head[u]; i != -1;i = e[i].next)
    {
        int v = e[i].v;
        if(vis[v] == 0)
        {
            dfs(v);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][1], dp[v][0]);
        }
    }
}

int main()
{
    int num, u, n, v;
    while(scanf("%d", &num) != EOF)
    {
        memset(head, -1, sizeof(head));
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        cnt = 0, root = -1;
        for(int i = 0; i < num; i++)
        {
            scanf("%d:(%d)", &u, &n);
            if(root == -1)
                root = u;
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &v);
                addedge(u, v);
            }
        }
        dfs(root);
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }
    return 0;
}
