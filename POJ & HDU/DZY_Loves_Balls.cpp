#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll c(ll a, ll b)
{
    ll x = 1, y = 1;
    b = min(b, a-b);
    if(b == 0)
        return 1;
    for(ll i = 1; i <= b; i++)
    {
        x *= a;
        y *= i;
        a--;
    }
    return x/y;
}

int main()
{
    ll n, m;
    while(cin >> n >> m)
    {
        ll j = min(n, m);
        ll ans = 0;
        for(ll i = 1; i <= j; i++)
            ans += i*c(n, i)*c(m, i);///第一个i为权重
        ll y = c(n+m, n);
        ll x = gcd(ans, y);
        cout << ans/x << '/' <<  y/x << endl;
    }
    return 0;
}
