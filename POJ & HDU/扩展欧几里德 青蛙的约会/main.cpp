#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>


using namespace std;

long long exgcd(long long a, long long b, long long& x, long long& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long ret = exgcd(b, a%b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

int main()
{
    long long x, y, m, n, l;
    long long t, k;
    while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) != EOF)
    {
        if((y-x) % l == 0)
        {
            printf("0\n");
            continue;
        }
        long long M = ((m-n)%l + l) % l;
        long long tmp = exgcd(M, l, t, k);
        if((y-x)%tmp == 0)
        {
            t *= ((y-x)/tmp);
            long long r = l / tmp;
            t = (t%r + r)%r;
            printf("%lld\n", t);
        }
        else
            printf("Impossible\n");
    }

    return 0;
}
