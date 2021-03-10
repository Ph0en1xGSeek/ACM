#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int father[1005];

int getFather(int x)
{
    if(father[x] == -1)
        return x;
    return father[x] = getFather(father[x]);
}

bool unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
    {
        father[fa] = fb;
        return true;
    }
    return false;
}

int main()
{
    int n , m;
    int a, b;
    int cnt;
    while(~scanf("%d%d", &n, &m) && n != 0)
    {
        if(m < n-1)
        {
            for(int i = 0; i < m; i++)
            {
                scanf("%d%d", &a, &b);
            }
            printf("NO\n");
        }
        else
        {
            cnt = 0;
            memset(father, -1, sizeof(father));
            for(int i = 0; i < m; i++)
            {
                scanf("%d%d", &a, &b);
                if(unions(a, b))
                    cnt++;
            }
            if(cnt >= n-1)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
    return 0;
}
