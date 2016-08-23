#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

priority_queue<int> q;
int arr[105];

int main()
{
    int num, k, tmp;
    while(~scanf("%d", &num))
    {
		while(!q.empty()) q.pop();
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < num; i++)
		{
			scanf("%d", &tmp);
			arr[tmp]++;
		}
		for(int i = 1; i <= 100; i++)
			q.push(arr[i]);
		scanf("%d", &k);
		for(int i = 0; i < k; i++)
		{
			tmp = q.top();
			q.pop();
			tmp--;
			q.push(tmp);
		}
		int ans = 0;
		tmp = q.top();
		q.pop();
		while(tmp > 0)
		{
			ans++;
			tmp = q.top();
			q.pop();
		}
		printf("%d\n", ans);
    }
    return 0;
}
