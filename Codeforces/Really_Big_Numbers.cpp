#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

long long sum(long long num)
{
    long long ans = 0;
    while (num != 0)
    {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

long long biSearch(long long l, long long r, long long num)
{
    while (l < r)
    {
        long long mid = (l+r) / 2;
        long long tmp = sum(mid);
        if(mid - tmp >= num)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    return l;
}

int main() {

    long long n;
    long long s;
    while (~scanf("%lld%lld", &n, &s))
    {
        long long ans = biSearch(1, n, s);
        if(ans != n)
        {
            ans = n - ans + 1;
            printf("%lld\n", ans);
        }
        else
        {
            if(n - sum(n) >= s)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}