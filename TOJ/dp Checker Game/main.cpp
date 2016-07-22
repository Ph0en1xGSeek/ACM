#include <iostream>
#include <cstring>
#include <stdio.h>
#define M 105

using namespace std;
int arr[M][M], dp[M][M];

int main()
{
    int num, ans;
    while(scanf("%d", &num), num)
    {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(arr));
        for(int i = 1; i <= num; i++)
            for(int j = 1; j <= num; j++)
                scanf("%d", &arr[i][j]);
        for(int i = 1; i <= num; i++)
            dp[1][i] = arr[1][i];
        for(int i = 2; i <= num; i++)
            for(int j = 1; j <= num; j++)
            {
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1]));
                dp[i][j] += arr[i][j];
            }
        for(int i = 1; i <= num; i++)
            ans = max(ans, dp[num][i]);
        printf("%d\n", ans);
    }
    return 0;
}
