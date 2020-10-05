#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MOD 1000000007

using namespace std;

long long quickPow(long long di, long long zhi, long long mod)
{
    long long tmp = di;
    long long sum = 1;
    while(zhi > 0)
    {
        if(zhi & 1)
            sum = (sum*tmp) % mod;
        tmp = (tmp * tmp) % mod ;
        zhi >>= 1;
    }
    return sum;
}

int main()
{
    int ca;
    long long num;
    scanf("%d", &ca);
    while(ca--)
    {
        long long ans;
        scanf("%lld", &num);
        if(num & 1)
        {
            ans = ((quickPow(2, num/2, MOD) * quickPow(2, num/2, MOD)) % MOD + MOD - 1) % MOD;
        }
        else
        {
            ans = (quickPow(2, num-1, MOD) + MOD - 1) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
