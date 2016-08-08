#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 50050

using namespace std;

int father[50050];

int getFather(int x)
{
    if(father[x] == -1)
        return x;
    else
        return father[x] = getFather(father[x]);
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
        father[fa] = fb;
}

int main()
{
    int n, m;
    int a, b;
    int ca = 1;
    while(~scanf("%d%d", &n, &m) && (n != 0 && m != 0))
    {
        memset(father, -1, sizeof(father));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            unions(a, b);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(father[i] == -1)
                ans++;
        printf("Case %d: %d\n", ca++,ans);
    }
    return 0;
}
