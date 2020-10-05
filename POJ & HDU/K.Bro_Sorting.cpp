#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 1000010

using namespace std;

int arr[M];
int m;

int lowbit(int x)
{
	return x & (-x);
}

int getSum(int n)
{
	int sum = 0;
	while(n >= 1)
	{
		sum += arr[n];
		n -= lowbit(n);
	}
	return sum;
}

void update(int n, int val)
{
	while(n <= m)
	{
		arr[n] += val;
		n += lowbit(n);
	}
}

int main()
{
    int ca;
    scanf("%d", &ca);
    int ans, cc = 1;
    while(ca--)
    {
		ans = 0;
		int tmp;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &tmp);
			update(tmp, 1);
			if(getSum(tmp-1) < tmp-1)
				ans++;
		}
		printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
