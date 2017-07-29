#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mod 200907

using namespace std;

long long pow(long long a, long long b)
{
    long long ans = 1, tmp = a;
    while(b > 0)
    {
        if(b&1)
            ans = (ans * tmp)%mod;
        tmp = (tmp * tmp)%mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    long long a, b, c, k;
    long long q;
    int ca;
    long long ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if(b + (b-a) == c)
        {
            ans = (((k-1)*(b-a))%mod + a)%mod;
        }
        else
        {
            q = b/a;
            ans = (pow(q, k-1) * a)%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
