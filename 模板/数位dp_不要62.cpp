#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int dp[10][3];
//dp[i][j]，i代表数字的位数，j代表状况
//dp[i][0],表示不存在不吉利数字
//dp[i][1],表示不存在不吉利数字，且最高位为2
//dp[i][2],表示存在不吉利数字

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 6; i++)//最大999999
    {
        dp[i][0] = 9 * dp[i-1][0] - dp[i-1][1];
        //最高位加上不含4的9个数字的状况，但因为会放6，所以要减去前一种开头为2的情况
        dp[i][1] = dp[i-1][0];//只有2
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + 10 * dp[i-1][2];
        //已经含有的前面放什么数都可以，或者是放一个4，或者是在2前面放6
    }
}

int solve(int n)///1到n（不算n）辛运数个数
{
    int counts = 0, tmp = n, flag = 0, arr[10], ans = 0;//ans为不幸运数
    while(n)
    {
        arr[++counts] = n % 10;
        n /= 10;
    }
    arr[counts + 1] = 0;
	///每一步都只计算到0~arr[i]-1开头的情况，然后这一位作为arr[i]开始计算下一位
    for(int i = counts; i >=1; i--)
    {
        ///0~arr[i]-1打头有完整的i-1位数
        ans += dp[i-1][2] * arr[i];
		
		///因为加上该位才变成不吉利的情况
        if(flag)
			///高位已经出现4或62了，所有数都要算
            ans += dp[i-1][0] * arr[i];
        else
        {
            ///若该位大于4，就要加上4+ i-1位幸运数构成的不幸运数
            if(arr[i] > 4)
                ans += dp[i-1][0];
            if(arr[i+1] == 6 && arr[i] > 2)
                ans += dp[i][1];
            if(arr[i] > 6)
                ans += dp[i-1][1];
        }
        if(arr[i] == 4 || (arr[i+1] == 6 && arr[i] == 2))
            flag = 1;
    }
    return tmp - ans;
}

int main()
{
    int n, m;
    init();
    while(scanf("%d%d", &n, &m) && n+m)
    {
        printf("%d\n", solve(m + 1) - solve(n));
    }
    return 0;
}
