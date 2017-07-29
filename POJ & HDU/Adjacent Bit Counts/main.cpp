#include <iostream>
#include <stdio.h>
#include <algorithm>
#define M 105

using namespace std;

long long dp[M][M][2];///dp[i][j][0]是长度为i j个相邻1 结尾为0的个数

void init()
{
    dp[0][0][0] = dp[0][0][1] = 0;
    dp[1][0][1] = dp[1][0][0] = 1;
    for(int i = 2; i <= 100; i++)
    {
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][0][0];
        for(int j = 1; j <= 100; j++)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
        }
    }
}

int main()
{
    init();
    int ca, num, a, b;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d %d %d", &num, &a, &b);
        printf("%d %I64d\n", num, dp[a][b][0] + dp[a][b][1]);
    }

    return 0;
}
