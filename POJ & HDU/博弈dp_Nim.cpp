#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int num, s;
int arr[25];
int dp[25][8890];///第i个人取的时候还剩j个

int dfs(int x, int y)
{
    if(dp[x][y] != -1)  return dp[x][y];
    for(int i = 1; i <= arr[x]; i++)
    {
        int tx = (x + 1) % (2*num), ty = y - i;
        if(ty < 0)  break;
        if(dfs(tx, ty) == 0)
            return dp[x][y] = 1;
    }
    return dp[x][y] = 0;
}

int main()
{
    while(scanf("%d", &num) && num != 0)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &s);
        for(int i = 0; i < 2*num; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < 2*num; i++)
            dp[i][0] = 1;///没得取为必胜态
        printf("%d\n", dfs(0, s));
    }
    return 0;
}
