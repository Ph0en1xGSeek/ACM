#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr1[25], arr2[25];
int dp[25][25][25][25];

int dfs(int l1, int r1, int l2, int r2, int sum)
{
    if(l1 > r1 && l2 > r2) return 0;
    if(dp[l1][r1][l2][r2]) return dp[l1][r1][l2][r2];
    int mx = 0;
    if(l1 <= r1)
    {
        mx = max(mx, sum-dfs(l1+1, r1, l2, r2, sum-arr1[l1]));
        mx = max(mx, sum-dfs(l1, r1-1, l2, r2, sum-arr1[r1]));
    }
    if(l2 <= r2)
    {
        mx = max(mx, sum-dfs(l1, r1, l2+1, r2, sum-arr2[l2]));
        mx = max(mx, sum-dfs(l1, r1, l2, r2-1, sum-arr2[r2]));
    }
    dp[l1][r1][l2][r2] = mx;
    return mx;
}

int main()
{
    int ca, num, sum;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(dp, 0, sizeof(dp));
        sum = 0;
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &arr1[i]);
            sum += arr1[i];
        }
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &arr2[i]);
            sum += arr2[i];
        }
        int ans = dfs(1, num, 1, num, sum);
        printf("%d\n", ans);
    }
    return 0;
}
