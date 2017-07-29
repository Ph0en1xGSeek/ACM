#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int num, from;
}arr[101][101];

int dp[101][101];
int st[105];
int top;

int main()
{
    int ca, n, m, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &m);
        for(int i= 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &arr[i][j].num);
        memset(dp, 0x7f, sizeof(dp));
        for(int i = 0; i < m; i++)
            dp[0][i] = arr[0][i].num;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j-1 >= 0 &&dp[i-1][j-1] + arr[i][j].num <= dp[i][j])
                {
                    dp[i][j] = dp[i-1][j-1] + arr[i][j].num;
                    arr[i][j].from = j-1;
                }
                if(dp[i-1][j] + arr[i][j].num <= dp[i][j])
                {
                    dp[i][j] = dp[i-1][j] + arr[i][j].num;
                    arr[i][j].from = j;
                }
                if(j+1 < m &&dp[i-1][j+1] + arr[i][j].num <= dp[i][j])
                {
                    dp[i][j] = dp[i-1][j+1] + arr[i][j].num;
                    arr[i][j].from = j+1;
                }
            }
        }
        int tmp = dp[n-1][0];
        int p = 0;
        for(int i = 1; i < m; i++)
            if(dp[n-1][i] <= tmp)
            {
                tmp = dp[n-1][i];
                p = i;
            }
        top = 0;
        st[0] = p;
        for(int i = n-1; i > 0; i--)
        {
            p = arr[i][p].from;
            st[++top] = p;
        }
        printf("Case %d\n", cc++);
        printf("%d", st[top]+1);
        for(int i = top-1; i >= 0; i--)
            printf(" %d", st[i]+1);
        printf("\n");
    }
    return 0;
}
