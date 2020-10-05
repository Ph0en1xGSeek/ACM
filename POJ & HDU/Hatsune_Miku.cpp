#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int arr[55][55];
int dp[105][55];
int notes[105];
bool vis[55];

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &arr[i][j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            scanf("%d", &notes[i]);
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            if(notes[i] < 0)
            {
                for(int j = 1; j <= m; j++)
                    for(int k = 1; k <= m; k++)
                        if(vis[k] && dp[i][j] < dp[i-1][k] + arr[k][j])
                            dp[i][j] = dp[i-1][k] + arr[k][j];
                memset(vis, true, sizeof(vis));
            }
            else if(notes[i] > 0)
            {
                for(int j = 1; j <= m; j++)
                    if(vis[j] && dp[i][notes[i]] < dp[i-1][j]+arr[j][notes[i]])
                        dp[i][notes[i]] = dp[i-1][j]+arr[j][notes[i]];
                memset(vis, false, sizeof(vis));
                vis[notes[i]] = 1;
            }
        }
        int mx = 0;
        for(int i = 1; i <= m; i++)
            if(dp[n][i] > mx)
                mx = dp[n][i];
        printf("%d\n", mx);
    }
    return 0;
}
