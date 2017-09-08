#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 10005
const long long INF = 0x7fffffffffffffff;

using namespace std;

int l1, l2, l3, c1, c2, c3;
int a, b;
int n;
long long arr[M];
long long dp[M];

int main()
{
    while(~scanf("%d%d%d%d%d%d", &l1, &l2, &l3, &c1, &c2, &c3))
    {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        scanf("%d", &n);
        arr[0] = 0;
        for(int i = 2; i <= n; i++)
            scanf("%lld", &arr[i]);
        for(int i = a; i <= b; i++)
            dp[i] = INF;

        dp[a] = 0;
        for(int i = a; i < b; i++)
        {
            for(int j = b; j > i; j--)
            {
                long long tmp = arr[j] - arr[i];
                if(tmp > 0 && tmp <= l1)
                    dp[j] = min(dp[j], dp[i] + c1);
                else if(tmp > l1 && tmp <= l2)
                    dp[j] = min(dp[j], dp[i] + c2);
                else if(tmp > l2 && tmp <= l3)
                    dp[j] = min(dp[j], dp[i] + c3);
            }
        }
        if(dp[b] == INF)
            printf("-1\n");
        else
            printf("%lld\n", dp[b]);
    }
    return 0;
}
