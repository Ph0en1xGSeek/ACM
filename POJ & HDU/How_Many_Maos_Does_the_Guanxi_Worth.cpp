#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 35
#define INF 0x3fffffff

using namespace std;

int n, m;
int mp[M][M];
int dp[M][M];

int solve(int x)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == x || j == x) dp[i][j] = INF;
            else dp[i][j] = mp[i][j];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    return dp[1][n];
}

int main()
{
    int a, b, c;
    int ans;
    while(~scanf("%d%d", &n, &m) && n != 0)
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i == j) mp[i][j] = 0;
                else mp[i][j] = INF;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            mp[a][b] = min(mp[a][b], c);
            mp[b][a] = mp[a][b];
        }
        for(int i = 2; i < n; i++)
            ans = max(ans, solve(i));
        if(ans == INF)
            printf("Inf\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
