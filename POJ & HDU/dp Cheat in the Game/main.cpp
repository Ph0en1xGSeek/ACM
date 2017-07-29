#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool dp[100005][2];///dp[i][0]为i个石子可以由偶数张牌抽完
                    ///dp[i][1]为奇数张
int arr[10005];

int main()
{
    int n, m, ans;
    while(scanf("%d%d", &n, &m) && n)
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        dp[arr[0]][1] = true;///放入第0个数
        for(int i = 1; i < n; i++)
        {
            for(int j = m; j > arr[i]; j--)///倒序,类似01背包，二维模拟三维，不受当前正在更新数的影响
            {
                if(dp[j-arr[i]][1])
                    dp[j][0] = true;
                if(dp[j-arr[i]][0])
                    dp[j][1] = true;
            }
            dp[arr[i]][1] = true;///为了不影响，最后放入自己
        }
        for(int i = 1; i <= m; i++)
            if(dp[i][1] && !dp[i][0])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
