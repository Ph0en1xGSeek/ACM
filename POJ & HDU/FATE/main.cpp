#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[105][105];
int exp[105];
int hp[105];

int main()
{
    int n, m, k, s;
    int i, K, j;
    while(scanf("%d%d%d%d", &n, &m, &k, &s) != EOF)
    {
        for(i = 1; i <= k; i++)
            scanf("%d%d", &exp[i], &hp[i]);
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= m; i++)
        {
            for(K = 1; K <= s; K++)
                for(j = 1; j <= k; j++)
                    if(i >= hp[j])
                     dp[i][K] = max(dp[i][K], dp[i-hp[j]][K-1] + exp[j]);
            if(dp[i][s] >= n)
                break;
        }
        printf("%d\n", m-i);
    }
    return 0;
}
