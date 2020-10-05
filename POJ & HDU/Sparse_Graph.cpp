#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 200005
#include <vector>
#define INF 20000000

using namespace std;

vector<int> v[M];
int d[M];
bool isVisted[M];
bool nex[M];
int ca, n, m;

void djikstra(int s)
{
    int mi, tmp;
    for(int i = 1; i <= n; i++)
    {
        isVisted[i] = false;
        nex[i] = false;
    }
    isVisted[s] = true;
    for(int i = 0; i < v[s].size(); i++)
        nex[v[s][i]] = true;
    for(int i = 1; i <= n; i++)
        if(!nex[i])
            d[i] = 1;
        else
            d[i] = INF;
    for(int i = 1; i < n; i++)//从1点开始要并入n个点
    {
        mi = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!isVisted[j] && d[j] < mi)//找到距离原点最近且没走过的点
            {
                tmp = j;
                mi = d[j];
            }
        }
        isVisted[tmp] = true;
        memset(nex, false, sizeof(nex));
        for(int i = 0; i < v[tmp].size(); i++)
            nex[v[tmp][i]] = true;
        for(int j = 1; j <= n; j++)//更新离原点的距离 无联系的暂不更新
            if(!isVisted[j] && d[j] > (nex[j]? INF:1) + d[tmp])
                d[j] = (nex[j]? INF:1) + d[tmp];
    }
}


int main()
{
    bool flag;
    int a, b;
    int s;
    scanf("%d", &ca);
    while(ca--)
    {

        memset(d, -1, sizeof(d));
        flag = false;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            v[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        scanf("%d", &s);
        if(n > 2*m)
        {
            for(int i = 0; i < v[s].size(); i++)
                d[v[s][i]] = 2;
            for(int i = 1; i <= n; i++)
                if(i != s)
                {
                    if(flag)
                        printf(" ");
                    flag = true;
                    if(d[i] == -1)
                        printf("1");
                    else
                        printf("2");
                }
            printf("\n");
        }
        else
        {
            djikstra(s);
            for(int i = 1; i <= n; i++)
                if(i != s)
                {
                    if(flag)
                        printf(" ");
                    flag = true;
                    if(d[i] == INF)
                        printf("-1");
                    else
                        printf("%d", d[i]);
                }
            printf("\n");
        }
    }
    return 0;
}
