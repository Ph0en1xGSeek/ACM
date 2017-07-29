#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 5050, MAXR = 100100, INF = 0x3f3f3f3f;
int first[MAXN], nex[MAXR * 2], v[MAXR * 2], w[MAXR * 2];
int d[2][MAXN];
int N, R, e, ans;
bool vis[MAXN];
typedef pair<int, int> pii;

void addedge(int a, int b, int c)
{
    nex[e] = first[a], v[e] = b, w[e] = c;
    first[a] = e ++;
}

void ReadGraph()
{
    int a, b, c;
    memset(first, -1, sizeof first);
    e = 0;
    while(R --)
    {
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
        addedge(b, a, c);
    }
}

void Dijkstra(int src, int t)
{
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for(int i = 0; i <= N; i ++)
        d[t][i] = INF;
    d[t][src] = 0;
    q.push(make_pair(d[t][src], src));
    memset(vis, false, sizeof vis);
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        int x = u.second;
        if(vis[x]) continue;
        vis[x] = true;
        for(int k = first[x]; k != -1; k = nex[k])
        {
            if(d[t][v[k]] > d[t][x] + w[k])
            {
                d[t][v[k]] = d[t][x] + w[k];
                q.push(make_pair(d[t][v[k]], v[k]));
            }
        }
    }
}

void cal()
{
    Dijkstra(1, 0); //到1的最短路
    Dijkstra(N, 1); //到N的最短路
    int shortest = d[0][N];
    ans = INF;
    for(int i = 0; i < e; i += 2)
    {
        int e1 = i, e2 = i + 1;//两条反向边正好连在一起
        int a = v[e2], b = v[e1];
        int res = d[0][a] + d[1][b] + w[e1];
        if (res < ans && res > shortest)
            ans = res;
        res = d[1][a] + d[0][b] + w[e2];
        if (res < ans && res > shortest)
            ans = res;
    }
}

int main()
{
    while(scanf("%d%d", &N, &R) != EOF)
    {
        ReadGraph();
        cal();
        printf("%d\n", ans);
    }
    return 0;
}
