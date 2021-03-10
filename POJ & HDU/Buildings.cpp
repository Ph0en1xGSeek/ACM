#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>


using namespace std;

int main()
{
    int n, m, x, y, ans;
    while(~scanf("%d%d%d%d", &n, &m, &x, &y))
    {
		if(n > m)
		{
			swap(n, m);
			swap(x, y);
		}
		if(n == m && (n&1) && x == y && x == (n+1)/2)
			ans = x-1;
		else
		{
			int a = min(y, m-y+1);
			int b = max(x-1, n-x);
			ans = min(a, b);
			ans = max(ans, (n+1)/2);
		}
		printf("%d\n", ans);
    }
    return 0;
}
