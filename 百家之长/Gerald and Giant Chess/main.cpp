#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
#define N 2333
typedef long long ll;
const ll mod = 1e9+7;

ll pow(ll a, ll n)
{
        ll res = 1;
        while(n)
        {
            if (n&1)
                res=res*a%mod;
            n >>= 1;
            a = a*a%mod;
        }
        return res;
}


struct P
{
        int x, y;
        P() {}
        P(int _x, int _y) { x=_x, y=_y; }
        bool operator < (P b) const {
                return x - b.x ? x < b.x : y < b.y;
        }
} p[N];

int h, w; int n;
const int M = 233333;
ll fac[M];
ll inv(ll a) { return pow(a, mod-2); }
ll _inv[M];
ll C(int x, int y)
{
        return fac[x] * _inv[y] % mod * _inv[x-y] % mod;
}
ll dp[N];
int main()
{
        fac[0] =1; _inv[0] = 1;
        for (int i=1;i<M;i++) fac[i] = fac[i-1] * i % mod, _inv[i] = inv(fac[i]);
        while (scanf("%d%d%d", &h, &w, &n) == 3)
        {
                for (int i=1;i<=n;i++)
                    scanf("%d%d", &p[i].x, &p[i].y);
                p[++n] = P(h, w);
                sort(p+1, p+n+1);
                for (int i=1;i<=n;i++)
                {
                        int x = p[i].x, y=  p[i].y;
                        dp[i] = C(x+y-2, x-1);
                        for (int j=1;j<i;j++)
                            if (p[j].x <= p[i].x && p[j].y<=p[i].y)
                            {
                                x = p[i].x - p[j].x + 1, y = p[i].y - p[j].y + 1;
                                ll t = dp[j] * C(x + y - 2, x - 1) % mod;
                                dp[i] = (dp[i] - t + mod) % mod;//减去第一次走到的是j的不合法点
                            }
                }
                printf("%I64d\n", dp[n]);
        }
        return 0;
}
