#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000010

using namespace std;

int arrp[MAXN];//用来存质数的
int times[MAXN];
bool vis[MAXN];//标记
int k;
void get_prime()
{
	k = 0;
	memset(vis, false, sizeof(vis));
	for(int i = 2; i <= MAXN; i++)
	{
		if(!vis[i])
		{
			arrp[k++] = i;
			for(int j = i; j < MAXN; j += i)
                vis[j] = true;
		}
	}
}

unsigned int fast_pow(unsigned int a, int b)
{
    unsigned int ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret = ret*a;
        a = (a * a);
        b >>= 1;
    }
    return ret;
}///2^32 正好利用溢出 不用取模

int main()
{
    get_prime();
    int ca, n, m;
    scanf("%d", &ca);
    unsigned int ans;
    while(ca--)
    {
        ans = 1;
        scanf("%d%d", &n, &m);
        memset(times, 0, sizeof(times));
        int i;
        for(i = 0; arrp[i] <= n && i < k; i++)
        {
            ///阶乘的质因分解，n以内2的倍数的个数+2^2的倍数的个数……得到2的指数
            for(long long j = arrp[i]; j <= n; j *= (long long)arrp[i])
                times[i] += n/j;
            for(long long j = arrp[i]; j <= m; j *= (long long)arrp[i])
                times[i] -= m/j;
            for(long long j = arrp[i]; j <= n-m; j *= (long long)arrp[i])
                times[i] -= (n-m)/j;

        }
        for(int j = 0; j < i; j++)
            ans *= fast_pow(arrp[j], times[j]);
        printf("%u\n", ans);
    }
    return 0;
}
