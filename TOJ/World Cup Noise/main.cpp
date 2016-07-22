#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[55][2] = {{0}};

int main()
{
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;
    for(int i = 3; i <= 50; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    int ca, num;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%d", &num);
        printf("Scenario #%d:\n", i);
        printf("%d\n", dp[num][0]+dp[num][1]);
        printf("\n");
    }
    return 0;
}
