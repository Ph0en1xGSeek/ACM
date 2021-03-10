#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int dp[1005];

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    for(int i = 3; i <= 1003; i++)
    {
        dp[i] = dp[i-1] + 4*dp[i-2];
        for(int j = i - 3; j >= 0; j-=2)
            dp[i] += 2*dp[j];
        for(int j = i - 4; j >= 0; j-=2)
            dp[i] += 3*dp[j];
    }
}

int main()
{
    init();
    int ca, n;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        scanf("%d", &n);
        printf("%d %d\n", i, dp[n]);
    }
    return 0;
}
