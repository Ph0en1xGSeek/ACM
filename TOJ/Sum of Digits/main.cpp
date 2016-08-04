#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[905][8105], d[905][8105];

void init()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 9; i++)
    {
        dp[i][i*i] = 1;
        d[i][i*i] = i;
    }
    for(int i = 1; i <= 900; i++)
        for(int j = 1; j <= 8100; j++)
            for(int k = 1; k <= 9; k++)
            {
                if(k > i || k*k > j)
                    break;
                if(dp[i-k][j-k*k] == 0 || dp[i-k][j-k*k] == 100)
                    continue;
                if(dp[i][j] == 0 || dp[i][j] > dp[i-k][j-k*k] + 1)
                {
                    dp[i][j] = dp[i-k][j-k*k] + 1;
                    d[i][j] = k;
                }
            }
}

int main()
{
    init();
    int ca, a,b;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &a, &b);
        if(dp[a][b] == 0 || a >= 900 || b >= 8100)
            printf("No solution\n");
        else
        {
            while(dp[a][b])
            {
                int tmp = d[a][b];
                printf("%d", tmp);
                a -= tmp;
                b -= tmp*tmp;
            }
            printf("\n");
        }
    }
    return 0;
}
