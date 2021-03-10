#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[2016][2016];
int dp2[2016][2016];

int main()
{
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    for(int i = 1; i < 2016; i++)
    {
        dp[i][0] = dp2[i][0] = 1;
    }
    dp2[0][0] = 1;
    for(int i= 1; i < 2016; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(i-1 > j) dp[i][j] = (dp[i][j]+dp[i-1][j])%1000000007;
            if(i > j-1) dp[i][j] = (dp[i][j]+dp[i][j-1])%1000000007;
        }
    }
    for(int i = 1; i < 2016; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(i-1 >= j) dp2[i][j] = (dp2[i][j]+dp2[i-1][j])%1000000007;
            if(i >= j-1) dp2[i][j] = (dp2[i][j]+dp2[i][j-1])%1000000007;
        }
    }

    int t, num, a, b;
    int ans1, ans2;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d-%d", &a, &b);
        ans1 = dp[a][b];
        ans2 = dp2[b][b];
        printf("Case #%d: %d %d\n", i, ans1, ans2);
    }
    return 0;
}
