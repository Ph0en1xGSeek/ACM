#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 55

using namespace std;
int arr[MAX][MAX];
int record[MAX][MAX];

int query(int matrix[][MAX], int n, int m)//高斯消元
{
    int i = 1, j = 1, r, k, t;
    while(i <= n && j <= m)//每一行找主元的位置
    {
	r = i;
	for(k = i; k <= n; k++)
	    if(matrix[k][j])
	    {
		r = k;
		break;
	    }
	if(matrix[r][j])
	{
	    if(r != i)
		for(k = 1; k <= m+1; k++)
		    swap(matrix[i][k], matrix[r][k]);//交换行
	    for(t = i+1; t <= n; t++)//并够造成上三角矩阵
		if(matrix[t][j])
		    for(k = i; k <= m+1; k++)
			matrix[t][k] ^= matrix[i][k];
	    i++;
	}
	j++;
    }
    for(t = i; t <= n; t++)
	if(matrix[t][m+1])	return -1;
    return  i-1;
}

int main(int argc, char **argv)
{
	int ca, n, m, k, tmp, ans;
	scanf("%d", &ca);
	for(int c = 1; c <= ca; c++)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &k);
			while(k--)
			{
			    scanf("%d", &tmp);
			    arr[tmp][i] = 1;
			}
		}
		memcpy(record, arr, sizeof(arr));
		printf("Case %d:\n", c);
		scanf("%d", &k);
		while(k--)
		{
		    memcpy(arr, record, sizeof(arr));
		    for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i][m+1]);
		    ans = query(arr, n, m);
		    if(ans == -1)	printf("0\n");
		    else	printf("%lld\n", 1LL << (m-ans));
		}
	}
	return 0;
}
