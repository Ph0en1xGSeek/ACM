#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x7fffffffffffffff

using namespace std;

int main()
{
    int n;
    long long tmp;
    while(~scanf("%d", &n))
    {
        long long ans = -INF;
        long long tot = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            tot += tmp;
            if(tot > ans)
                ans = tot;
            if(tot < 0)
            {
                tot = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
