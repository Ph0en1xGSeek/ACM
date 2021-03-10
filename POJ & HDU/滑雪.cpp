#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct node
{
    int p;
    int num;
}arr[10086];
int source[105][105];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

int main()
{
    int n, m;
    int dp[105][105];

    while(~scanf("%d%d", &m, &n))
    {
        memset(source, 0, sizeof(source));
        for(int i = 0; i < n*m; i++)
        {
            arr[i].p = i;
            scanf("%d", &arr[i].num);
            int y = i % n +1;
            int x = i /n + 1;
            source[x][y] = arr[i].num;
        }
        sort(arr, arr+n*m, cmp);
        memset(dp, 0, sizeof(dp));
        int ans =  0;
        for(int i = 0; i < n*m; i++)
        {
            int p = arr[i].p;
            int y = p % n +1;
            int x = p /n + 1;
            if(source[x-1][y] != arr[i].num)
                dp[x][y] = max(dp[x-1][y], dp[x][y]);
            if(source[x+1][y] != arr[i].num)
                dp[x][y] = max(dp[x+1][y], dp[x][y]);
            if(source[x][y-1] != arr[i].num)
                dp[x][y] = max(dp[x][y-1], dp[x][y]);
            if(source[x][y+1] != arr[i].num)
                dp[x][y] = max(dp[x][y+1], dp[x][y]);
            dp[x][y] ++;
            ans = max(ans, dp[x][y]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
