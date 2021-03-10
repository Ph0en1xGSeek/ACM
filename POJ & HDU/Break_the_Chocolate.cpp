#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int ca, cc = 1;
    long long n, m, k;
    scanf("%d", &ca);
    long long ans1, ans2;
    while(ca--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        ans1 = n*m*k-1;
        ans2 = (long long)(ceil(log2(n))+ceil(log2(m)) + ceil(log2(k)));
        printf("Case #%d: %I64d %I64d\n", cc++, ans1, ans2);
    }
    return 0;
}
