#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100005

using namespace std;

struct edge
{
    int v;
    int nex;
}edges[M<<1];

int head[M];
int deep[M];
int father[M][20];///father[i][j] is (1<<j)th (grand)father of i
int cnt;

int n, q;

void addEdge(int u, int v)
{
    edges[cnt].v = v;
    edges[cnt].nex = head[u];
    head[u] = cnt++;
    edges[cnt].v = u;
    edges[cnt].nex = head[v];
    head[v] = cnt++;
}

void dfs(int cur, int fa)
{
    deep[cur] = deep[fa] + 1;
    for(int i = head[cur]; i != -1; i = edges[i].nex)
    {
        int v = edges[i].v;
        if(v != fa)
        {
            father[v][0] = cur;
            dfs(v, cur);
        }
    }
}

void InitLCA()
{
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            father[j][i] = father[father[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b)
{
    if(deep[a] < deep[b])
        swap(a, b);
    for(int i = 19; i >= 0; i--)
    {
        if(deep[father[a][i]] >= deep[b])
            a = father[a][i];
    }
    if(a == b)  return a;
    for(int i = 19; i >= 0; i--)
    {
        if(father[a][i] != father[b][i])
        {
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}

int len(int a, int b)
{
    int anc = lca(a, b);
    return (deep[a] + deep[b] - 2*deep[anc]);
}

int main()
{
    int to;
    int a, b, c;
    while(~scanf("%d%d", &n, &q))
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 2; i <= n; i++)
        {
            scanf("%d", &to);
            addEdge(i, to);
        }
        deep[0] = 0;
        father[1][0] = 1;
        dfs(1, 0);
        InitLCA();

        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            int anc1 = lca(a, b);
            int anc2 = lca(b, c);
            int anc3 = lca(a, c);
            if(deep[anc1] < deep[anc2])
                anc1 = anc2;
            if(deep[anc1] < deep[anc3])
                anc1 = anc3;
            int ans  = len(anc1, a);
            ans = max(ans, len(anc1, b));
            ans = max(ans, len(anc1, c));
//            for(int i = 1; i <= n; i++)
//                printf("%d ", deep[i]);
//            printf("\n");
            printf("%d\n", ans+1);
        }
    }
    return 0;
}
