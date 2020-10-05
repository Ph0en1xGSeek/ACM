#include <iostream>
#include <stdio.h>]
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

double Heron(int a, int b, int c)
{
	if(a+b < c) return 0.0;
	double p = (a+b+c)*0.5;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

vector<int> vt;///三角形
int arr[15];
double dp[1<<12];

int main()
{
    int num;
    while(~scanf("%d", &num) && num != 0)
    {
		for(int i = 0; i < num; i++)
			scanf("%d", &arr[i]);
		memset(dp, 0, sizeof(dp));
		vt.clear();
		sort(arr, arr+num);
		for(int i = 0; i < num-2; i++)
			for(int j = i+1; j < num-1; j++)
				for(int k = j+1; k < num; k++)
				{
					if(arr[i] + arr[j] <= arr[k]) break;
					int tmp = ((1<<i)|(1<<j)|(1<<k));
					dp[tmp] = Heron(arr[i], arr[j], arr[k]);
					vt.push_back(tmp);
				}
		for(int i = 0; i < (1<<num); i++)
		{
			for(int j = 0; j < vt.size(); j++)
			{
				if(i&vt[j]) continue;
				dp[i|vt[j]] = max(dp[i|vt[j]], dp[i]+dp[vt[j]]);
			}
		}
		printf("%.2lf\n", dp[(1<<num)-1]);
    }
    return 0;
}
