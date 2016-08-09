#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    long long m, n;
    while(~scanf("%I64d%I64d", &n, &m) && n != 0)
    {
        long long fenzi = n * (m-1);
        long long fenmu = m*m;
        long long gcd = __gcd(fenzi, fenmu);
        fenzi /= gcd;
        fenmu /= gcd;
        printf("%I64d/%I64d\n", fenzi, fenmu);
    }
    return 0;
}
