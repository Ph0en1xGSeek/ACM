#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

long long prime[60];

long long notPrime(long long num, int m)///1~num²»»¥ÖÊµÄ
{
    long long ans = 0, tmp, cnt;
    for(long long i = 1; i < (long long)(1<<m); i++)
    {
        tmp = 1;
        cnt = 0;
        for(long long j = 0; j < m; j++)
            if(i & (long long)(1<<j))
            {
                cnt++;
                tmp *= prime[j];
            }
        ///容斥原理
        if(cnt & 1)
            ans += num / tmp;
        else
            ans -= num / tmp;
    }
    return ans;
}

int main()
{
    long long a, b, n;
    int ca, m;
    scanf("%d", &ca);
    int cc = 1;
    while(ca--)
    {
        m = 0;
        scanf("%lld%lld%lld", &a, &b, &n);
        ///质因分解
        for(long long i = 2; i*i <= n; i++)
        {
            if(n % i == 0)
            {
                prime[m++] = i;
                while(n % i == 0)
                    n /= i;
            }
        }
        if(n > 1) prime[m++] = n;
        printf("Case #%d: %lld\n", cc++, b-notPrime(b, m) - (a-1 - notPrime(a-1, m)));
    }
    return 0;
}
