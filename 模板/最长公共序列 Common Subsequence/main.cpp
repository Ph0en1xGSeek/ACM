#include <iostream>
#include <stdio.h>
#include <string.h>
#define M 1000

using namespace std;
char s1[M], s2[M];
int dp[M][M];//s1第i个和s2第j个之前（不包括）的最长长度
int main()
{
    while(scanf("%s %s", s1, s2) != EOF)
    {
        int len1 = strlen(s1), len2 = strlen(s2);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}
