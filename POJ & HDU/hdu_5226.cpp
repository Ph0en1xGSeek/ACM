#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 100005

using namespace std;

long long p;
long long fac[M], inv[M];

long long pow(long long a, long long b, long long p)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans  = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void init()
{
    inv[0] = fac[0] = 1;
    for(int i = 1; i < p && i < M; i++)
    {
        fac[i] = (fac[i-1] * i%p) % p;
        inv[i] = pow(fac[i], p-2, p);
    }
}

long long C(long long n, long long m)
{
    if(m > n) return 0;
    return (fac[n] * inv[m] % p * inv[n-m] % p);
}

long long Lucas(long long n, long long m)
{
    if(m > n) return 0;
    long long ans = 1;
    while(n || m )
    {
        ans = ans * C(n%p, m%p) % p;
        n /= p;
        m /= p;
    }
    return ans;
}

int main()
{
    int x1, y1, x2, y2;
    while(~scanf("%d%d%d%d%I64d", &x1, &y1, &x2, &y2, &p))
    {
        init();
        long long ans = 0;
        for(int i = y1; i <= y2; i++)
        {
            ans  = (ans + Lucas(x2+1, i+1) - Lucas(x1, i+1) + p) % p;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
