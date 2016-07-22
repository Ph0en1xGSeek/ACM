#include <iostream>
#include <stdio.h>
#include <vector>
#define M 10086
#include <cstring>

using namespace std;

vector<int> e[M];
int low[M], dfn[M], cut[M];
int t;

void tarjan(int u, int fa)//双向边防回头
{
    dfn[u] = low[u] = ++t;
    int len = e[u].size();
    for(int i = 0; i < len; i++)
    {
        int v = e[u][i];
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])
                cut[u]++;
        }
        else if(dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}

int main()
{
    int n, m, from, to;
    while(scanf("%d%d", &n, &m), n)
    {
        t = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(cut, 0, sizeof(cut));
        for(int i = 0; i < n; i++)
            e[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &from, &to);
            e[from].push_back(to);
            e[to].push_back(from);
        }
        int sum = 0;
        int max_cut = -10000;
        for(int i = 0; i < n; i++)
        {
            if(!dfn[i])
            {
                sum++;
                tarjan(i, -1);
                cut[i]--;//每个根节点-1
            }
        }
        for(int i = 0; i < n; i++)
            max_cut = max(max_cut, cut[i]);
        printf("%d\n", sum + max_cut);
    }
    return 0;
}
