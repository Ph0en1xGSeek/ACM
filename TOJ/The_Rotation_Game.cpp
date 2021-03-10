#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[25], depth;

bool ok(int * p)
{
	int k=p[7];
	return (k==p[8])&&(k==p[9])&&(k==p[12])&&(k==p[13])&&(k==p[16])&&(k==p[17])&&(k==p[18]);
}

int c[5],ans;
int va[]={7,8,9,12,13,16,17,18};
int pos[]={1,2,3,4,6,5,8,7};//字典序，满足相反步数相减为4
char out[100];

int count(int *p)///八个格子里最多的数 8-count为达到合法至少需要的步数
{
	c[1]=c[2]=c[3]=0;
	for(int i=0;i<8;i++)
		c[p[va[i]]]++;
	return max(c[1],max(c[2],c[3]));
}
void rotate(int * p,int a,int b,int c,int d,int e,int f,int g)//旋转
{
	int tp = p[a];
	p[a] = p[b], p[b] = p[c], p[c] = p[d], p[d] = p[e], p[e] = p[f], p[f] = p[g], p[g] = tp;
}
int dfs(int * p,int now,int pre)
{
	if(depth-now < 8 - count(p))
		return 0;
	if(now >= depth)
        return 0;
	int tmp[25];
	for(int w = 0; w < 8; w++)
	{
		for(int i = 1; i <= 24; i++)
			tmp[i] = p[i];
        int i = pos[w];
		if(pre - i == 4 || i - pre == 4) continue;///相反走法剪枝
		switch(i)
		{
			case 1:rotate(tmp,1,3,7,12,16,21,23);
			out[now]='A';
			break;
			case 2:rotate(tmp,2,4,9,13,18,22,24);
			out[now]='B';
			break;
			case 3:rotate(tmp,11,10,9,8,7,6,5);
			out[now]='C';
			break;
			case 4:rotate(tmp,20,19,18,17,16,15,14);
			out[now]='D';
			break;
			case 5:rotate(tmp,23,21,16,12,7,3,1);
			out[now]='F';
			break;
			case 6:rotate(tmp,24,22,18,13,9,4,2);
			out[now]='E';
			break;
			case 7:rotate(tmp,5,6,7,8,9,10,11);
			out[now]='H';
			break;
			case 8:rotate(tmp,14,15,16,17,18,19,20);
			out[now]='G';
			break;
		}
		if(ok(tmp))
		{
			out[now+1]='\0';
			ans = tmp[7];
			return 1;
		}
		if(dfs(tmp, now + 1, i))
			return 1;
	}
	return 0;
}

int main()
{
	while(scanf("%d",a+1)&&a[1])
	{
		for(int i = 2; i <= 24; i++)
			scanf("%d", a+i);
		if(ok(a))
		{
			printf("No moves needed\n");
			printf("%d\n", a[7]);
		}
		else
		{
			depth=1;
			while(1)
			{
				if(dfs(a,0,-100))
					break;
				depth++;
			}
			printf("%s\n", out);
			printf("%d\n", ans);
		}
	}
	return 0;
}
