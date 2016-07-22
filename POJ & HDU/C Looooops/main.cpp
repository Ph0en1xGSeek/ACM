#include <iostream>
#include <stdio.h>

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
    long long A, B, C, K;
    long long  x, y;

    while(scanf("%I64d %I64d %I64d %I64d",&A,&B,&C,&K))
    {
        if(!A && !B && !C && !K)
            break;
        long long a = C;
        long long b = B - A;
        long long n = 1LL<<K;
        long long d = exgcd(a, n, x, y);
        if(b % d)
            cout << "FOREVER" << endl;
        else
        {
            x = (x*(b/d)) % n;
            x = (x%(n/d) + n/d)%(n/d);
            printf("%I64d\n", x);
        }
    }
    return 0;
}
