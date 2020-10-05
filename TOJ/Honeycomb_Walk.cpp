#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
    int dp[15][17][17];
    int step[6][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,-1},{-1,1}};
    memset(dp, 0, sizeof(dp));
    dp[0][8][8] = 1;
    for(int k = 1; k <= 14; k++)
    for(int i = 1; i < 16; i++)
    for(int j = 1; j < 16; j++)
    for(int s = 0; s < 6; s++)
        dp[k][i][j] += dp[k-1][i-step[s][0]][j-step[s][1]];
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        printf("%d\n", dp[num][8][8]);
    }
    return 0;
}
