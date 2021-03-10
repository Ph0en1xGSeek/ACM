#include <iostream>
#define Max 102
#define MaxM 1005
#include <cstdio>
#include <cstring>
#define INF 99999999

using namespace std;
int w[Max], v[Max];
int dp[Max][MaxM];//dp[i][j]放i个用了j时间的最大值

int main()
{
    int n, m, l;
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d%d", &n, &m, &l);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &v[i]);
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j <= l; j++)
            {
                dp[i][j] = -INF;
                dp[0][j] = 0;
            }
        }

        for(int k = 1; k <= n; k++)
            for(int i = m; i >= 1; i--)
                for(int j = l; j >= w[k]; j--)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[k]]+v[k]);
        int ans = 0;
        for(int j = 1; j <= l; j++)
            ans = max(ans, dp[m][j]);
        printf("%d\n", ans);
    }
    return 0;
}
