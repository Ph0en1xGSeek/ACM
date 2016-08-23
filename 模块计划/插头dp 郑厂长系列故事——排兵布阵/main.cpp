#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
bool arr[101][11];
int dp[2][1088];

int solve(int f)///黑白二色
{
	int p = 0, q = 1;///p为前置状态,q为当前状态
	int ans = 0, u, v;
	memset(dp[p], -1, sizeof(dp[p]));
	dp[p][0] = 0;///什么也不放
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if((i+j)%2 != f) continue;
			memset(dp[q], -1, sizeof(dp[q]));///默认不可达
			for(int k = (1<<m)-1; k >= 0; k--)
			{
				if(dp[p][k] == -1) continue;
				if(arr[i][j])///可以放士兵
				{
					v = (1 << j);
					if(!(v&k) && !(k&(v<<1)) && !(k&(v>>1)) && !(k&(v>>2)))///上方两格、右上、左上、左二
					{
						u = k | v;
						if(dp[q][u] < dp[p][k] + 1)
							dp[q][u] = dp[p][k] +1;
					}
				}
				///不放
				u = k;
				if(u & (1<<j))
					u -= (1<<j);///拿走
				if(dp[q][u] < dp[p][k])
					dp[q][u] = dp[p][k];
			}
			p ^= 1, q ^= 1;
		}
	}
	for(int i = (1<<m)-1; i >= 0; i--)
		if(ans < dp[p][i])
			ans = dp[p][i];
	return ans;
}

int main()
{
	int tmp;
	while(~scanf("%d%d", &n, &m))
	{
		memset(arr, false, sizeof(arr));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &tmp);
				arr[i][j] = tmp;
			}
		int ans = solve(0) + solve(1);
		printf("%d\n", ans);
	}
    return 0;
}
