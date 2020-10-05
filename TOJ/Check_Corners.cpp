#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int val[310][310];
int dp[310][310][9][9];
int half[310];
int n, m, q;

void init()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j][0][0] = val[i][j];
    for(int ii = 0; ii <= half[n]; ii++)
        for(int jj = 0; jj <= half[m]; jj++)
            if(ii + jj)
            {
                for(int i = 1; i+(1<<ii)-1 <= n; i++)
                    for(int j = 1; j+(1<<jj)-1 <= m; j++)
                    {
                        if(ii) dp[i][j][ii][jj] = max(dp[i][j][ii-1][jj], dp[i+(1<<(ii-1))][j][ii-1][jj]);
                        else dp[i][j][ii][jj] = max(dp[i][j][ii][jj-1], dp[i][j+(1<<(jj-1))][ii][jj-1]);
                    }
            }
}

int rmq(int x1, int y1, int x2, int y2)
{
    int k1 = half[x2-x1+1];
    int k2 = half[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dp[x1][y1][k1][k2], dp[x1][y2][k1][k2]), max(dp[x2][y1][k1][k2], dp[x2][y2][k1][k2]));
}

int main()
{
    int x1, y1, x2, y2;
    half[0] = -1;
    for(int i = 1; i <= 305; i++)
        if((i&(i-1)) == 0) half[i] = half[i-1]+1;
        else half[i] = half[i-1];
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &val[i][j]);
        init();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            int ans = rmq(x1, y1, x2, y2);
            printf("%d ", ans);
            if(val[x1][y1] == ans || val[x1][y2] == ans || val[x2][y1] == ans || val[x2][y2] == ans)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
