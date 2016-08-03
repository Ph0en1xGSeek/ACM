#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mod 1000000007

using namespace std;

long long dp[1010][1010];
long long arr1[1010];
long long arr2[1010];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            scanf("%lld", &arr1[i]);
        for(int j = 1; j <= m; j++)
            scanf("%lld", &arr2[j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(arr1[i] == arr2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                dp[i][j] = ((((dp[i][j] + dp[i-1][j])%mod + dp[i][j-1])%mod) - dp[i-1][j-1] + mod)%mod;
            }
        printf("%lld\n", dp[n][m]);
    }

    return 0;
}
