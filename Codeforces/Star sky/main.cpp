#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 105
using namespace std;

int sum[M][M][15];

int main()
{
    int n, q, c;
    int x, y, s;
    int t, x1, y1;
    while(~scanf("%d%d%d", &n, &q, &c))
    {
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &s);
            sum[x][y][s]++;
        }
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                for(int k = 0; k <= c; k++)
                {
                    sum[i][j][k] += sum[i][j-1][k] + sum[i-1][j][k] - sum[i-1][j-1][k];
                }
            }
        }

        for(int i = 0; i < q; i++)
        {
            scanf("%d%d%d%d%d", &t, &x, &y, &x1, &y1);
            int ans = 0;
            for(int j = 0; j <= c; j++)
            {
                int tmp = sum[x1][y1][j] + sum[x-1][y-1][j] - sum[x-1][y1][j] - sum[x1][y-1][j];
                ans += tmp*((j+t) % (c+1));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
