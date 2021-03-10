#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 1000006
#define M 100005
#include <queue>

using namespace std;
const long long INF = 1e17;

struct Edge
{
    int to;
    int nex;
    long long w;
}e[N<<1];

struct node
{
    int p;
    long long d;
    node(){}
    node(int a, long long b):p(a), d(b){}
    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};

int head[M+N], cnt;
int n, m;

void addedge(int u, int v, long long w)
{
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}

long long da[2][N+M];
bool isVisted[N+M];
bool nex[N+M];

void djikstra(int s, long long d[])
{
    priority_queue<node> q;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n+m; i++)
        d[i] = INF;
    memset(isVisted, false, sizeof(isVisted));
    d[s] = 0;
    q.push(node(s, 0));
    while(!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int u = tmp.p;
        if(isVisted[u]) continue;
        isVisted[u] = true;
        for(int i = head[u]; i != -1; i = e[i].nex)
        {
            int v = e[i].to;
            int w = e[i].w;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push(node(v, d[v]));
            }
        }
    }
}

int main()
{
    int ca;
    int s;
    long long t;
    int tmp;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
        scanf("%d%d", &n, &m);
        for(int j = n+1; j < n+1+m; j++)
        {
            scanf("%I64d%d", &t, &s);
            for(int k = 0; k < s; k++)
            {
                scanf("%d", &tmp);
                addedge(tmp, j, t);
                addedge(j, tmp, 0);
            }
        }
        djikstra(1, da[0]);
        djikstra(n, da[1]);
        long long ans = INF;
        for(int j = 1; j <= n; j++)
        {
            if(max(da[0][j], da[1][j]) < ans)
                ans = max(da[0][j], da[1][j]);
        }
        if(ans == INF)
        {
            printf("Case #%d: Evil John\n", i);
            continue;
        }
        printf("Case #%d: %I64d\n", i, ans);
        bool flag = false;
        for(int i = 1; i <= n; i++)
            if(max(da[0][i], da[1][i]) == ans)
            {
                if(!flag)
                    printf("%d", i);
                else
                    printf(" %d", i);
                flag = true;
            }
        printf("\n");
    }
    return 0;
}
