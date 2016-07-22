#include <iostream>
#include <stdio.h>

using namespace std;
int dp[10086];

int main()
{
    int ca, m, n;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &m, &n);
        if(m <= n)
        {
            printf("Grass\n");
            continue;
        }
        dp[m] = 0;
        for(int i = m-1; i >= 0; i--)
        {
            dp[i] = 0;
            for(int j = 1; j <= n && i+j <= m; j++)
                if(dp[i+j] == 0)
                    dp[i] = 1;
        }
        if(dp[0] == 0)
            printf("Rabbit\n");
        else
            printf("Grass\n");
    }
    return 0;
}
