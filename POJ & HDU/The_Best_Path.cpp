#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 100010
#define M 500010

using namespace std;

int degree[N];
int arr[N];

int main()
{
    int ca, n, m, a, b;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(degree, 0, sizeof(degree));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            degree[a]++;
            degree[b]++;
        }
        int ans = 0;
        int odd = 0;
        for(int i = 1; i <= n; i++)
        {
            if(degree[i]&1)
            {
                odd++;
                ans ^= arr[i];
            }
            if((degree[i]/2)&1)
                ans ^= arr[i];
        }
        if(odd > 2 || odd == 1)
            printf("Impossible\n");
        else if(odd == 2)
            printf("%d\n", ans);
        else if(odd == 0)
        {
            int ma = 0;
            for(int i = 1; i <= n; i++)
                ma = max(ma, ans^arr[i]);
            printf("%d\n", ma);
        }
    }
    return 0;
}
