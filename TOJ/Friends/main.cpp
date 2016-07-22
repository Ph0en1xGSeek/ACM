#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int father[105];

int getFather(int x)
{
    if(father[x] == 0)
        return x;
    father[x] = getFather(father[x]);
    return father[x];
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
    int ca, n, m;
    int a, b;
    int counts;
    scanf("%d", &ca);
    while(ca--)
    {
        counts = 0;
        memset(father, 0, sizeof(father));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            unions(a, b);
        }
        for(int j = 1; j <= n; j++)
        {
            if(father[j] == 0)
                counts++;
        }
        printf("%d\n", counts);
    }
    return 0;
}
