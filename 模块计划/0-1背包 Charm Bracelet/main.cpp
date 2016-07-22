#include <iostream>

using namespace std;

int w[3403];
int d[3403];
int dp[12881] = {0};//把前i个物品放入容量为j的背包中的最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> d[i];
    }
	for (int i = 1; i <= n; i++)//用一维数组模拟，理解用二维好理解
	{
		for (int j = m; j >= w[i]; j--)//if (w[i]>j) dp[i,j] = dp[i-1,j]
		{
			dp[j] = max(dp[j-w[i]] + d[i], dp[j]);//else dp[i,j] = max(dp[i-1,j-w[i]]+d[i],dp[i-1,j])
		}
	}
	cout << dp[m] << endl;
    return 0;
}
