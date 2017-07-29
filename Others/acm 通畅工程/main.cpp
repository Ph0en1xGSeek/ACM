#include <stdio.h>

using namespace std;

int father[1005] = {0};

int getFather(int n)
{
    if(father[n] == 0)
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

int main()
{
    int m, n;
    while(scanf("%d", &n), n)
    {
        scanf("%d", &m);
        for(int i = 1; i <= n; i++)
            father[i] = 0;
        int a, b;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            unions(a, b);
        }
        int counts = 0;
        for(int i = 1; i <= n; i++)
        {
            if(father[i] == 0)
                counts++;
        }
        printf("%d\n", counts - 1);
    }
    return 0;
}
