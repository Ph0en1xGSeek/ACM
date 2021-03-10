#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 205
#define INF 50000005

using namespace std;

int a[M], b[M];
int dp[M][M];

int DP(int l, int r)
{
    int mi = INF;
    if(l+1 >= r) return 0;
    if(l+2 == r) return (a[l+1] + b[l] + b[r]);
    if(dp[l][r] != -1) return dp[l][r];
    for(int i = l+1; i < r; i++)
        mi = min(mi, DP(l, i) + DP(i, r) + a[i] + b[l] + b[r]);
    return dp[l][r] = mi;
}

int main()
{
    int ca, num, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, -1, sizeof(dp));
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= num; i++)
            scanf("%d", &b[i]);
        int ans = DP(0, num+1);
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
