#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool isVisR[1000010];
bool isVisC[1000010];

int main()
{
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    int n, q;
    char str;
    int p;
    while(~scanf("%d%d", &n, &q))
    {
        long long rcnt = 0;
        long long rsum = 0;
        long long ccnt = 0;
        long long csum = 0;
        memset(isVisR, false, sizeof(isVisR));
        memset(isVisC, false, sizeof(isVisC));
        while(q--)
        {
            scanf(" %c%d", &str, &p);
            if(str == 'R')
            {
                if(isVisR[p])
                    printf("0\n");
                else
                {
                    isVisR[p] = true;
                    rcnt++;
                    rsum += p;
                    printf("%lld\n", (long long)p*n + (long long)n*(n+1)/2 - (long long)ccnt*p - csum);
                }
            }
            else if(str == 'C')
            {
                if(isVisC[p])
                    printf("0\n");
                else
                {
                    isVisC[p] = true;
                    ccnt++;
                    csum += (long long)p;
                    printf("%lld\n", (long long)p*n + (long long)n*(n+1)/2 - (long long)rcnt*p - rsum);
                }
            }
        }
    }
    return 0;
}
