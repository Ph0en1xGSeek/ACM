#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define ll long long

using namespace std;

ll pow(ll a, ll b, ll p)
{
    ll tmp = a;
    ll ans = 1;
    while(b > 0)
    {
        if(b&1)
            ans  = (ans * tmp) % p;
        tmp = (tmp * tmp) % p;
        b >>= 1;
    }
    return ans;
}


int main()
{
    ll x, y, p;
    while(~scanf("%lld%lld%lld", &x, &y, &p))
    {
        ll ans = pow(x, y, p-1);
        if(ans == 0)
            ans = p-1;
        printf("%lld\n", ans);
    }
    return 0;
}
