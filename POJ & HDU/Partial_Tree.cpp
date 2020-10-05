#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int f[2020];
int dp[2020];

int main()
{
    int ca, n;
    scanf("%d", &ca);
    while(ca--)
    {
        for(int i = 1; i <= 2019; i++)
            dp[i] = -100000;
        dp[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n-1; i++)
            scanf("%d", &f[i]);
        int ans = n * f[1];///n个点都有一个度了
        for(int i = 2; i <= n-1; i++)
            f[i] -= f[1];///之后每增加度数，都要先舍弃原来的一个度的权值
        for(int i = 1; i <= n-2; i++)
        {
            for(int j = i; j <= n-2; j++)
            {
                dp[j] = max(dp[j], dp[j-i]+f[i+1]);///再增加i个度，先舍弃1个度的权值然后增加i+1个权值
            }
        }
        printf("%d\n", ans + dp[n-2]);
    }
    return 0;
}
