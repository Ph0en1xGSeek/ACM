#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    unsigned long long n, m;
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%I64u%I64u", &n, &m);
        int ans = 0;
        while(n != m)
        {
            if(m % n != 0)///n的所有质因数次数都比m的小
            {
                printf("-1\n");
                break;
            }
            unsigned long long gcd = __gcd(m/n, n);///最多能补齐多少
            if(gcd == 1)///质因数不相同导致无法补齐
            {
                printf("-1\n");
                break;
            }
            n *= gcd;///补齐
            ans++;
        }
        if(n == m)
            printf("%d\n", ans);
    }
    return 0;
}
