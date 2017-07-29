#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int abs(int a)
{
    if(a < 0)
        return -a;
    return a;
}

int arr[55][55];

int main()
{
    int ca, n, m, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <=n; i++)
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &arr[i][j]);
                if(arr[i][j] != 0)
                    ans++;
            }
        for(int i = 1; i <= n+1; i++)
            for(int j = 1; j <= m+1; j++)
                ans += abs(arr[i][j] - arr[i][j-1]);
        for(int j = 1; j <= m+1; j++)
            for(int i = 1; i <= n+1; i++)
                ans += abs(arr[i][j] - arr[i-1][j]);
        printf("%d\n", ans);
    }
    return 0;
}
