#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000000
#include <cmath>

using namespace std;

bool check(long long n)
{
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)
        {
            n /= i;
            if(n % i == 0)
                return false;
        }
    return true;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        long long num;
        scanf("%lld", &num);
        long long t1 = (long long)sqrt(num);
        long long t2 = t1 + 1;
        while(t1 > 1 && !check(t1)) t1--;
        while(!check(t2)) t2++;
        long long ans = abs(t2*t2 - num);
        if(t1 >= 2) ans = min(ans , num - t1*t1);
        printf("%lld\n", ans);
    }
    return 0;
}
