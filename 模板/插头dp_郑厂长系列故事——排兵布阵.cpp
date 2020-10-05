#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
bool arr[101][11];
int dp[2][1088];


/*
把图分割成了两个不互相干扰的部分分开处理
dp[p]: 更新上一个位置时各个状态的达到的最大值
dp[q]: 更新当前位置时各个状态达到的最大值
更新第一行第一个位置的时候，除了0以外都是不可达状态。更新第二个位置的时候，只有前面更新过的位置的状态才是可达状态。
从第二行开始，位置j，每个更新的状态在j之前的表示当前行的状态，j只后的表示的时前一行的状态。
当然，由于是空一格更新一格的，中间跳过的个的标记也代表上一行的状态，当前位置的状态由于在上一行就没有更新，所以就是两行以前的状态

 */

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
