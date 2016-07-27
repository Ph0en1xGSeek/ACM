#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 410
#define INF 2147483647
#include <queue>

using namespace std;

int n, maxFlow;
int source = 0, sink;
int net[M][M], d[M];///距离

int bfs()
{
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[source] = 1;
    q.push(source);
    int k;
    while(!q.empty())
    {
        k = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(d[i] == -1 && net[k][i])
            {
                d[i] = d[k] + 1;
                q.push(i);
            }
        }
        if(k == sink)
            return 1;
    }
    return 0;
}

int dfs(int cur, int cap)
{
    if(cur == sink)
        return cap;
    int tot = cap, tmp;
    for(int i = 0; i < n; i++)
    {
        if(d[i] == d[cur] + 1 && net[cur][i])
        {
            tmp = dfs(i, min(tot, net[cur][i]));
            net[cur][i] -= tmp;
            net[i][cur] += tmp;
            tot -= tmp;
        }
    }
    return cap - tot;
}

void dinic()
{
    maxFlow = 0;
    while(bfs())
        maxFlow += dfs(source, INF);
}

int main()
{
    int f, d;
    int fNum, dNum;
    int tmp;
    while(scanf("%d%d%d", &n, &f, &d) != EOF)
    {
        sink = 2*n+f+d+1;
        memset(net, 0 ,sizeof(net));
        for(int i = 1; i <= f; i++)///源点到食物
            net[source][i] = 1;
        for(int i = 1; i <= d; i++)///饮料到汇点
            net[2*n+f+i][sink] = 1;
        for(int i = 1; i <= n; i++)///牛到牛
            net[f+i][f+n+i] = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &fNum, &dNum);
            for(int j = 1; j <= fNum; j++)
            {
                scanf("%d", &tmp);
                net[tmp][f+i] = 1;
            }
            for(int j = 0; j < dNum; j++)
            {
                scanf("%d", &tmp);
                net[f+n+i][f+2*n+tmp] = 1;
            }
        }
        n = sink + 1;///n变为总点数
        dinic();
        printf("%d\n", maxFlow);
    }
    return 0;
}
