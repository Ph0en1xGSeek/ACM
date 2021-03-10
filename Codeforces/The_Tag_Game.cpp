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
}arr[5*M];

int cnt;
int head[2*M];

void addEdge(int u, int v)
{
    arr[cnt].v = v;
    arr[cnt].nex = head[u];
    head[u] = cnt++;

    arr[cnt].v = u;
    arr[cnt].nex = head[v];
    head[v] = cnt++;
}

int disA[2*M];
int disB[2*M];

void dfs(int cur, int deep, int dis[])
{
    if(dis[cur] != -1) return;
    dis[cur] = deep;
    for(int i = head[cur]; i != -1; i = arr[i].nex)
    {
        dfs(arr[i].v, deep+1, dis);
    }
}

int main()
{
    int n, k;
    int u, v;
    while(~scanf("%d%d", &n, &k))
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        memset(disA, -1, sizeof(disA));
        memset(disB, -1, sizeof(disB));

        dfs(1, 0, disA);
        dfs(k, 0, disB);

        int mx = 0;

//        for(int i = 1; i <= n; i++)
//        {
//            printf("%d ", disA[i]);
//        }
//        printf("\n");

        for(int i = 1; i <= n; i++)
        {
            if(disB[i] < disA[i])
            {
                mx = max(mx, disA[i]);
            }
        }

        printf("%d\n", 2*mx);
    }
    return 0;
}
