#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 30003
#define INF 2147483647
#include <queue>

using namespace std;

struct Edge
{
    int nex, to, cap;
}edge[260001];

int head[M], vis[M], dis[M], cur[M];
queue<int> q;
int p ,c, n, cnt = 0;

void add(int a, int b, int c)
{
    edge[cnt].to = b;
    edge[cnt].cap = c;
    edge[cnt].nex = head[a];
    head[a] = cnt++;

    edge[cnt].to = a;
    edge[cnt].cap = 0;
    edge[cnt].nex = head[b];
    head[b] = cnt++;
}

int bfs()
{
    while(!q.empty())
        q.pop();
    memset(dis, -1, sizeof(dis));
    dis[1] = 1;
    q.push(1);
    int k;
    while(!q.empty())
    {
        k = q.front();
        q.pop();
        for(int i = head[k]; i != -1; i = edge[i].nex)
            if(dis[edge[i].to] == -1 && edge[i].cap > 0)
            {
                int to = edge[i].to;
                dis[to] = dis[k] + 1;
                q.push(to);
                if(to == n) return 1;
            }
    }
    return 0;
}

int dfs(int u, int cap)
{
    if(u == n)
        return cap;
    int tag = 0, c;///tag 已经扩展了多少
    for(int &i = cur[u]; i != -1; i = edge[i].nex)///弧优化
    {
        int to = edge[i].to;
        if(dis[to] == dis[u] + 1 && edge[i].cap > 0)
        {
            c = dfs(to, min(cap-tag, edge[i].cap));
            edge[i].cap -= c;
            edge[i^1].cap += c;
            tag += c;
            if(tag == cap) return tag;
        }
    }
    return tag;
}

int dinic()
{
    int maxFlow = 0;
    while(bfs())
    {
        for(int i = 0; i <= n; i++)
            cur[i] = head[i];
        maxFlow += dfs(1, INF);
    }
    return maxFlow;
}

int main()
{
    int from, to;
    while(scanf("%d%d%d", &p, &c, &n) != EOF)
    {
        memset(head, -1, sizeof(head));
        memset(vis, 0 , sizeof(vis));
        cnt = 0;
        add(1, 2, INF);
        while(c--)
        {
            scanf("%d%d", &from, &to);
            add(from*2, to*2-1, INF);
            add(to*2 ,from*2-1, INF);
        }
        while(n--)
        {
            scanf("%d", &from);
            vis[from] = 1;
        }
        for(int i = 2; i <= p; i++)
            if(vis[i])
            {
                add(i*2-1, i*2, INF);
                add(i*2, 2*p+1, INF);
            }
            else
                add(i*2-1, i*2, 1);
        n = 2*p+1;
        printf("%d\n", dinic());
    }
    return 0;
}
