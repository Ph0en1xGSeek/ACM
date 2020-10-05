#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[50];
int dp[2][1<<20];

int main()
{
    int ca, n, m, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        int pre = 0, cur = 1;///¹ö¶¯Êý×é
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            memcpy(dp[cur], dp[pre], sizeof(dp[cur]));
            for(int j = 0; j < (1<<20); j++)
                if(dp[pre][j^arr[i]] != 0)
                    dp[cur][j] += dp[pre][j^arr[i]];
            pre ^= 1, cur ^= 1;
        }
        long long ans = 0;
        for(int i = m; i < (1 << 20); i++)
            ans += (long long)dp[pre][i];
        printf("Case #%d: %I64d\n", cc++, ans);
    }
    return 0;
}
