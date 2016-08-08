#include <iostream>
#include <vector>
#define Max 1005
#include <cstring>
#define INF 0x3f3f3f3f
#include <stdio.h>

using namespace std;

struct node
{
    int to;
    int capacity;
    int ret;//反向边
};

vector<node> e[Max];
bool vis[Max];

void add(int from, int to, int cap)
{
    node n, m;
    n.to = to; n.capacity = cap; n.ret = e[to].size();
    m.to = from; m.capacity = 0; m.ret = e[from].size();
    e[from].push_back(n);
    e[to].push_back(m);
}

int bfs(int head, int tail, int flow)
{
    if(head == tail)
        return flow;
    vis[head] = true;
    for(int i = 0; i < e[head].size(); i++)
    {
        node &tmp = e[head][i];
        if(vis[tmp.to] == false && tmp.capacity > 0)
        {
            int d = bfs(tmp.to, tail, min(flow, tmp.capacity));//能否增广看最小容量
            if(d > 0)
            {
                tmp.capacity -= d;
                e[tmp.to][tmp.ret].capacity += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int head, int tail)
{
    int flow = 0;
    while(1)
    {
        memset(vis, false, sizeof(vis));
        int tmp = bfs(head, tail, INF);
        if(tmp == 0)//没有增广路
            return flow;
        flow += tmp;
    }
}

int main()
{
    int n, m;
    int x, y, z;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < m; i++)
            e[i].clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
        }
        printf("%d\n", maxFlow(1, m));
    }
    return 0;
}
