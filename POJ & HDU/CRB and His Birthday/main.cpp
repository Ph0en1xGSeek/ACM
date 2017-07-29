#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int w;
    int dp[2048];
    int a;
    int b;
    int ca, m, n;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &w, &a, &b);
            for(int j = m; j >= w; j--)
                dp[j] = max(dp[j], dp[j-w]+a+b);
            for(int j = w; j <= m; j++)
                dp[j] = max(dp[j], dp[j-w] + a);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
