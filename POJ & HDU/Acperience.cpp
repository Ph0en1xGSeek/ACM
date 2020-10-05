#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100010

using namespace std;

long long w[M];

int main()
{
    int ca;
    long long n;
    long long total, powTotal;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%I64d", &n);
        total = powTotal = 0;
        for(long long i = 0 ; i < n; i++)
        {
            scanf("%I64d", &w[i]);
            if(w[i] < 0)
                w[i] = -w[i];
            total += w[i];
            powTotal += w[i] * w[i];
        }
        long long fenzi = n*powTotal - total*total;
        long long gcd = __gcd(fenzi, n);
        printf("%I64d/%I64d\n", fenzi/gcd, n/gcd);
    }
    return 0;
}
