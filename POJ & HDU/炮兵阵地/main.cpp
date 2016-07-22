#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,sum,num,sta[1<<11],cot[1<<11],dp[102][65][65],map[105];
bool fit(int x,int y)
{
	if(x&y)
		return 0;
	return 1;
}
void init()//找合法的排法
{
	 sum=1<<m;num=0;
	for(int i=0;i<sum;i++)
	{
		if(i&(i<<1)||i&(i<<2))
			continue;
		sta[num]=i;
		int tem=i,count=0;
		while(tem)
		{
				count++;
			tem&=tem-1;//最后一位1变0，也就是数有几个1
		}
		cot[num++]=count;
	}
}
void DP()
{
	int ans=0;
	for(int i=0;i<num;i++)
	{
		if(!fit(map[1],sta[i]))
			continue;
		dp[1][0][i]=cot[i];
		if(ans<dp[1][0][i])
				ans=dp[1][0][i];
	}
	for(int i=2;i<=n;i++)//枚举行
		for(int j=0;j<num;j++)//i-1排法
        {
            if(!fit(map[i-1],sta[j]))
                continue;
            for(int k=0;k<num;k++)//i的排法
			{
				if(!fit(sta[k],sta[j])||!fit(map[i],sta[k]))
					continue;
				for(int l=0;l<num;l++)//i-2
				{
					if(!fit(sta[k],sta[l])||!fit(sta[j],sta[l])||!fit(map[i-2],sta[l])||!dp[i-1][l][j])
						continue;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][j]+cot[k]);
					if(ans<dp[i][j][k])
						ans=dp[i][j][k];
				}
			}
        }

			printf("%d\n",ans);
}
int main()
{
	char s;
	scanf("%d%d",&n,&m);
	getchar();
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&s);
			if(s=='H')
			{
				int tem=1<<(j-1);
				map[i]+=tem;
			}
		}
		getchar();
	}
	DP();
	return 0;
}
