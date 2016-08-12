#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool sign[66];
bool bit[66];
long long f[66], res[66];

void init()
{
    f[0] = 1;
    for(int i = 1; i <= 61; i++)
        f[i] = 2*f[i-1];
}

int main()
{
    init();
    long long ca, n, k, cc = 1;
    scanf("%I64d", &ca);
    while(ca--)
    {
        scanf("%I64d%I64d", &n, &k);
        for(int i = 0; i < k; i++)
        {
            res[i] = f[i];
            sign[i] = true;
        }
        long long d = f[k]-1ll-n;
        if(d%2)
        {
            res[k-1]++;
            d++;
        }
        long long x = d/2;
        long long cnt = 0;
        while(x)
        {
            bit[cnt++] = x%2;
            x /= 2;
        }
        for(int i = 0; i < cnt; i++)
            if(bit[i])
                sign[i] = false;
        printf("Case #%I64d:\n", cc++);
        for(int i = 0; i < k; i++)
        {
            printf("%I64d ", res[i]);
            if(sign[i])
                printf("+\n");
            else
                printf("-\n");
        }
    }
    return 0;
}
