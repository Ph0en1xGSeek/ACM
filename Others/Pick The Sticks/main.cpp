#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

long long ans;
long long dp[4005][3];
long long a[1005];
long long v[1005];

int main()
{
    int ca;
    int num, len;
    scanf("%d", &ca);
    for(int c = 1; c <= ca; c++)
    {
        memset(dp, 0, sizeof(dp));
        ans = 0;
        scanf("%d%d", &num, &len);
        len *= 2;
        for(int i = 0; i < num; i++)
        {
            scanf("%lld%lld", &a[i], &v[i]);
            a[i] *= 2;
            ans = max(ans, v[i]);
        }

        for(int i = 0; i < num; i++)
        {
            for(int j = len; j >= a[i] / 2; j--)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(j >= a[i])
                        dp[j][k] = max(dp[j][k], dp[j-a[i]][k] + v[i]);
                    if(k > 0)
                        dp[j][k] = max(dp[j][k], dp[j-a[i]/2][k-1] + v[i]);
                    ans = max(ans, dp[j][k]);
                }
            }
        }

        printf("Case #%d: %lld\n", c, ans);
    }
    return 0;
}
