#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 1000010
#define INF 0x7fffffff

using namespace std;

int arr[N];
int dp[N];///第i次循环 第j个数作为最后一个组的最后一个元素的最大值
int mTo[N];///前j-1个数分成i-1组的最大值

int main()
{
    int m, n;
    int tmp;
    while(~scanf("%d%d", &m, &n))
    {
        memset(dp, 0, sizeof(dp));
        memset(mTo, 0, sizeof(mTo));
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(int i = 1; i <= m; i++)
        {
            tmp = -INF;
            for(int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j-1]+arr[j], mTo[j-1]+arr[j]);
                mTo[j-1] = tmp;
                tmp = max(tmp, dp[j]);
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}
