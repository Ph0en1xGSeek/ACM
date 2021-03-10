#include <iostream>
#define ll long long
#include <cstdio>
#include <cstring>

using namespace std;
ll dp[20][3];///0无异常的所有， 1第一位为9， 2已有49
int arr[20];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 20; i++)
    {
        ///满足条件的=之前满足条件的随便加一个数-4+开头为9的满足条件的
        dp[i][0] = 10 * dp[i-1][0] - dp[i-1][1];
        ///加9
        dp[i][1] = dp[i-1][0];
        ///4+9打头符合条件和不符合条件的随便加一个
        dp[i][2] = dp[i-1][1] + 10 * dp[i-1][2];
    }
    int ca;
    ll num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%lld", &num);
        num++;
        int counts = 0;
        while(num)
        {
            arr[++counts] = num % 10;
            num /= 10;
        }
        arr[counts + 1] = 0;
        int flag = 0;
        ll ans = 0;///有49的个数
        for(int i = counts; i >= 1; i--)
        {
            ///0~arr[i]-1打头的都会有完整的i-1位
            ans += dp[i-1][2] * arr[i];
            ///高位已经出现49了，这时候即使是没有49的也要计算进去
            if(flag == 1)
                ans += dp[i-1][0] * arr[i];
            ///第一个49要加上9打头的合法个数
            else if(arr[i] > 4)
            {
                ans += dp[i-1][1];
            }
            ///高位出现49
            if(arr[i] == 9 && arr[i+1] == 4)
            {
                flag = 1;
            }

        }
        printf("%lld\n", ans);

    }


    return 0;
}
