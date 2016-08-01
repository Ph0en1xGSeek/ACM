#include <iostream>
#include <stdio.h>
#define N 13
#define M 1 << N
#define mod 100000000
#include <cstring>

using namespace std;

int state[M], mp[N], dp[N][M];
///dp[i][j] 第i行为止用排法j的排法
int judge1(int x)///本行有无相邻
{
    if(x&(x << 1))
        return 0;
    return 1;
}

int judge2(int i, int k)//排法k与地图是否冲突
{
    if(mp[i] & state[k])
        return 0;
    return 1;
}

int main()
{
    int n, m;
    int tmp, total, counts;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(mp, 0, sizeof(mp));
        memset(state, 0, sizeof(state));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &tmp);
                if(tmp == 0)
                    mp[i] += 1 << (m-j);
            }
        }
        total = (1<<m) - 1;
        counts = 0;
        for(int i = 0; i <= total; i++)///筛选合法状态
            if(judge1(i))
                state[counts++] = i;
        for(int i = 0; i < counts; i++)///第一行
            if(judge2(1, i))
                dp[1][i] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < counts; j++)
            {
                if(!judge2(i, j))
                    continue;
                for(int k = 0; k < counts; k++)
                {
                    if(!judge2(i-1, k))
                        continue;
                    if(!(state[j]&state[k]))///i-1行可以放且不与i行排法j冲突
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < counts; i++)
            ans = (ans + dp[n][i])%mod;
        printf("%d\n", ans);
    }
    return 0;
}
