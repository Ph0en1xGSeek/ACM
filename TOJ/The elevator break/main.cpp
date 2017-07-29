#include <iostream>
#include <stdio.h>
#define M 50001

using namespace std;

int main()
{
    long long c[M], u[M], d[M];
    long long num, tmp, ans;
    while(scanf("%lld", &num) != EOF)
    {
        for(int i = 0; i < num; i++)
            scanf("%lld", &c[i]);
        for(int i = 0; i < num; i++)
        {
            scanf("%lld%lld", &u[i], &d[i]);
            u[i] *= c[i];
            d[i] *= c[i];
        }
        tmp = 0;
        for(int i = num-1; i >= 0; i--)
        {
            tmp += d[i+1];
            d[i] += d[i+1];
        }
        ans = tmp;
        for(int i = 1; i < num; i++)
            u[i] += u[i-1];
        for(int i = 1; i < num; i++)
        {
            tmp += u[i-1];
            tmp -= d[i];
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
