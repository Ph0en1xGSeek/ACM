#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int vis[1<<13+5];

int main()
{

    int p;
    scanf("%d", &p);
    long long aa;
    int a, b;
    while(~scanf("%lld", &aa) && aa != 0)
    {
        int flag = 1;
        memset(vis, 0, sizeof(vis));
        a = (int)aa % p;
        scanf("%d", &b);
        if(b >= p)
        {
            printf("0\n");
            continue;
        }
        vis[a] = 1;
        int x;
        int tmp = a;
        for(x = 2; ;x++)
        {
            a = (a*tmp)%p;
            if(a == b)
                break;
            if(vis[a] == 1)
            {
                flag = 0;
                break;
            }
            vis[a] = 1;
        }
        if(flag)
            printf("%d\n", x);
        else
            printf("0\n");
    }
    return 0;
}
