#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[1005][35];//i时刻换树j次最多的苹果
int arr[1002];

int main()
{
    memset(dp, 0, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    int t, w;
    scanf("%d%d", &t, &w);
    for(int i = 0; i < t; i++)
        scanf("%d", &arr[i]);
    if(arr[0] == 1)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else if(arr[0] == 2)
    {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }

    for(int i = 2; i <= t; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + arr[i-1] % 2;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);

                if(j % 2 == arr[i-1]-1)//正好有苹果从这棵树掉落
                {
                    dp[i][j]++;
                }
            }
        }
    }
    int ans = dp[t][0];
    for(int i = 0; i <= w; i++)
        ans = max(ans, dp[t][i]);
    printf("%d\n", ans);
    return 0;
}
