#include <iostream>
#define M 20
#include <cstring>
#include <queue>
#define INF 0x7fffffff
#include <stdio.h>

using namespace std;
int dfn[M];
int S = 1, T;//源点/汇点
int cap[M][M];

/*struct Edge
{
    int v;
    int c;
    int next;
}e[M];

int head[M];

void add(int u, int v, int cap)
{
    e[cnt].v = v;
    e[cnt].c = cap;
    e[cnt].next = head[u];
    head[u] = cnt++;
    e[cnt].v = u;
    e[cnt].c = 0;
    e[cnt].next = head[v];
    head[v] = cnt++;
}*/

bool bfs()
{
    memset(dfn, 0, sizeof(dfn));
    queue<int> q;
    int u, v;
    dfn[S] = 1;
    q.push(S);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 1; i <= T; i++)
        {
            if(!dfn[i] && cap[u][i] > 0)
            {
                dfn[i] = dfn[u] + 1;
                q.push(i);
            }
        }
    }
    return dfn[T] != 0;
}

int dfs(int u, int now)//计算扩增量
{
    int uu = now;
    if(u == T)
        return now;
    for(int i = 1; i <= T && uu; i++)
    {
        if(dfn[i] == dfn[u] + 1 && cap[u][i] > 0)
        {
            int tt = dfs(i, min(uu, cap[u][i]));
            uu -= tt;
            cap[u][i] -= tt;
            cap[i][u] += tt;
        }

    }
    if(!uu)//剪枝
        dfn[u] = -2;
    return now - uu;
}

int dinic()
{
    int ans = 0, flow;
    while(bfs())//还能不能到汇点
    {
        while(flow = dfs(1, INF))//深搜出残量扩展
            ans += flow;
    }
    return ans;
}

int main()
{
    int m, ca;
    int from, to, capacity;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%d%d", &T, &m);
        memset(cap, 0, sizeof(cap));
        for(int j = 0; j < m; j++)
        {
            scanf("%d%d%d", &from, &to, &capacity);
            cap[from][to] += capacity;//要判重边边边边
        }
        int ans = dinic();
        printf("Case %d: %d\n", i, ans);
    }


    return 0;
}
