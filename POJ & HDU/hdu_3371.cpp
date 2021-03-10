#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define M 505

using namespace std;

int father[M];

struct edge
{
    int a;
    int b;
    int len;
    bool operator<(const edge &g) const
    {
        return len < g.len;
    }
}arr[M*M], e;

int getFather(int n)
{
    if(father[n] != -1)
    {
        return father[n] = getFather(father[n]);
    }
    return n;
}

int main()
{
    int ca;
    int n, m, k;
    int sum;
    scanf("%d", &ca);
    while(ca--)
    {
        sum = 0;
        memset(father, -1, sizeof(father));
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].len);
        }
        sort(arr, arr+m);
        int num, cur = 0;
        for(int i = 0; i < k; i++)
        {
            int tmp, tmp1;
            scanf("%d", &num);
            scanf("%d", &tmp);
            int tmpFa = getFather(tmp);
            for(int j = 1; j < num; j++)
            {
                scanf("%d", &tmp1);
                int tmpFa2 = getFather(tmp1);
                if(tmpFa2 != tmpFa)
                {
                    father[tmpFa2] = tmpFa;
                    cur++;
                }
            }
        }
        int pos = 0;
        while(cur < n-1 && pos < m)
        {
            int fa = getFather(arr[pos].a);
            int fb = getFather(arr[pos].b);
            if(fa != fb)
            {
                father[fa] = fb;
                cur++;
                sum += arr[pos].len;
            }
            pos++;
        }
        if(cur != n-1)
            printf("-1\n");
        else
            printf("%d\n", sum);
    }
    return 0;
}
