#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
long long dp[65]={0,1,2,3};
void init()
{
  for(int i=4;i<=60;i++)
	  dp[i]=dp[i-1]+dp[i-3]+1;
}
int main()
{
	init();
	int n;
	while(~scanf("%d",&n))
	{
		printf("%lld\n",dp[n]);
	}
	return 0;
}
/*状态转移方程： dp[i]=dp[i-1]+dp[i-3]+1。
  dp[i]的含义是到i这个位置为止，有多少种方案数，也就是答案。因为dp表示的是合法的解，所以之前一定已经至少放了一个木桩了。dp[i-1]代表的是当前位置i不放木桩，
dp[i-3]代表的是当前位置放，因为间隔为2，所以不论前面第三个位置有没有，当前位置i都可以放置1个木桩，至于最后加上的一个1，开始没怎么理解，其实它代表的是前面i-1
个位置都没放置木桩，而在当前位置i放置一个木桩，这也是一组合法的解，故加上1。*/
