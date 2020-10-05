#include <iostream>
#include <stdio.h>

using namespace std;
int dp[1111];

int main()
{
    int m, n, flag;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        dp[m] = 0;
        for(int i = m-1; i >= 0; i--)
        {
            dp[i] = 0;
            for(int j = 1; j <= n && i+j <= m; j++)
                if(dp[i+j] == 0)
                    dp[i] = 1;
        }
        flag = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dp[i] == 0 || i >= m)
            {
                if(flag)
                    printf(" %d", i);
                else
                {
                    printf("%d", i);
                    flag = 1;
                }
            }
        }
        if(flag)
            printf("\n");
        else
            printf("none\n");
    }
    return 0;
}
