#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#define N 103
using namespace std;

int a[N][N], m, n;
int h[N],l[N],markh[N],markl[N];

int find2()
{
	for (int i = 1; i <= n; i++)
        if (h[i] < 0)
            return i;
	return 0;
}

int find1()
{
	for (int i = 1; i <= m; i++)
        if (l[i] < 0)
            return i;
	return 0;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
		{
			scanf("%d", &a[i][j]);
			h[i] += a[i][j];
			l[j] += a[i][j];
		}
	int t=0,t1=0;
	while ((t=find2())||(t1=find1()))///找到和为负的行列
	{
        if (t)
        {
            markh[t]++;
            for (int i=1;i<=m;i++)
            {
                l[i] = l[i] - (a[t][i] << 1);
                a[t][i] = -a[t][i];
            }
            h[t] = -h[t];
        }
        else
        {
            markl[t1]++;
            for (int i=1;i<=n;i++)
            {
                h[i] = h[i]- (a[i][t1] << 1);
                a[i][t1] = -a[i][t1];
            }
            l[t1] = -l[t1];
        }
	}
	int num=0,num1=0;
	for (int i=1;i<=n;i++)
        if (markh[i]&1) num++;
	printf("%d ",num);
	for (int i=1;i<=n;i++)
        if (markh[i]&1)
            printf("%d ",i);
	printf("\n");
	for (int i=1;i<=m;i++)
        if (markl[i]&1)  num1++;
    printf("%d ",num1);
    for (int i=1;i<=m;i++)
     if (markl[i]&1)
        printf("%d ",i);
    printf("\n");
}
