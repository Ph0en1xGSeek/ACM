#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, m;
    char arr[20][110];
    int left[20];
    int right[20];
    int dp[20][2];
    int cnt;
    int cntFloor[20];
    while(~scanf("%d%d", &n, &m))
    {
        cnt = 0;
        memset(cntFloor, 0, sizeof(cntFloor));
        memset(dp, 0, sizeof(dp));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for(int i = n; i >= 1; i--)
            scanf("%s", arr[i]);
        for(int i = 1 ; i <= n; i++)
        {
            for(int j = 0; j < m+2; j++)
                if(arr[i][j] == '1')
                {
                    left[i] = j;
                    break;
                }
            for(int j = left[i]; j < m+2; j++)
                if(arr[i][j] == '1')
                {
                    right[i] = j;
                    cntFloor[i]++;
                    cnt++;
                }
            if(cntFloor[i] == 0)
            {
                right[i] = 0;
                left[i] = m+1;
            }
        }
        if(cnt == 0)
        {
            printf("0\n");
        }
        else
        {

            int i = 1;
            if(cntFloor[i] != 0)///µÚÒ»²ã±ØÐëÕ¾ÓÒ±ß
            {
                left[i] = right[i];
                dp[i][0] = right[i];
                dp[i][1] = right[i];
            }
            else
            {
                dp[i][0] = dp[i][1] = 0;
                left[i] = right[i];
            }
            cnt -= cntFloor[i];
            if(cnt > 0)
                for(i = 2; i <= n; i++)
                {
                    dp[i][0] = m+1-left[i-1] + dp[i-1][0] + m+1-left[i];
                    dp[i][0] = min(dp[i][0], m+1-right[i-1] + dp[i-1][1] + m+1-left[i]);
                    dp[i][1] = left[i-1] + dp[i-1][0] + right[i];
                    dp[i][1] = min(dp[i][1], right[i-1] + dp[i-1][1] + right[i]);
                    dp[i][0]++;
                    dp[i][1]++;
                    cnt -= cntFloor[i];
                    if(cnt == 0)
                        break;
                }
            int ans = min(dp[i][0], dp[i][1]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
