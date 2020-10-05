#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[5005];
    int dp[50005];
    int c, h;
    while(~scanf("%d%d", &c, &h))
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= h; i++)
            scanf("%d", &arr[i]);
        for(int i = 1; i <= h; i++)
            for(int j = c; j >= arr[i]; j--)
                if(dp[j] < dp[j-arr[i]]+arr[i])
                    dp[j] = dp[j-arr[i]]+arr[i];
        printf("%d\n", dp[c]);
    }
    return 0;
}
