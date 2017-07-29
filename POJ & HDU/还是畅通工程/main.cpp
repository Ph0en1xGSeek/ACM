#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int father[101] ;

struct edge
{
    int from;
    int to;
    int w;
}e[10000];

int getFather(int n)
{
    if(father[n] == -1)
        return n;
    father[n] = getFather(father[n]);
    return father[n];
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
        father[fa] = fb;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int kruskal(int j)
{
    int x, y, cost = 0;
    sort(e + 1, e + j + 1, cmp);
    for(int i = 1; i <= j ; i++)
    {
        x = getFather(e[i].from);
        y = getFather(e[i].to);
        if(x != y)
        {
            cost += e[i].w;
            father[x] = y;
        }
    }
    return cost;
}


int main()
{
    int n, j = 0;
    int x, y;
    while(scanf("%d", &n), n)
    {
        memset(father, -1, sizeof(father));
        int a, b, c;
        for(int i = 1; i <= (n*(n-1))/2; i++)
        {
            scanf("%d%d%d", &a, &b, &c);

                e[i].from = a;
                e[i].to = b;
                e[i].w = c;

        }
        printf("%d\n", kruskal((n*(n-1))/2));
    }
    return 0;
}
