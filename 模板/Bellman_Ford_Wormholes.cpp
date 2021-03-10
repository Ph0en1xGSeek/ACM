#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int u, v, cap;
}edge[5040];

int cnt;
int dis[520];
int n, m, w;

int Bellman_Ford()
{
    int i;
    for(i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for(i = 1; i <= n; i++)
    {
        int flag = 0;
        for(int j = 0; j < cnt; j++)
        {
            if(dis[edge[j].v] > dis[edge[j].u] + edge[j].cap)
            {
                flag = 1;
                dis[edge[j].v] = dis[edge[j].u] + edge[j].cap;
            }
        }
        if(flag == 0)   break;
    }
    return (i == n+1);//是否有负环
}

void add(int u, int v, int c)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt++].cap = c;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d%d", &n, &m, &w);
        cnt = 0;
        int a, b, c;
        while(m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
        }
        while(w--)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, -c);
        }
        int ans = Bellman_Ford();
        if(ans == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
