#include <stdio.h>
#include <memory.h>

#define MAXN 50001
int father[MAXN],rank[MAXN];

void Init(int n)
{
	int i;
	for(i=1;i<=n;i++)
		father[i]=i;
	memset(rank,0,sizeof(rank));
}

int Find_Set(int x)
{
	if(x!=father[x])
	{
		int fx=Find_Set(father[x]);
		rank[x]=(rank[x]+rank[father[x]])%3;	//注意 是rank[father[x]]而不是rank[fx]
		father[x]=fx;
	}
	return father[x];
}

bool Union(int x,int y,int type)
{
	int fx,fy;
	fx=Find_Set(x);
	fy=Find_Set(y);
	if(fx==fy)
	{
		if((rank[y]-rank[x]+3)%3!=type)return true;		//这个关系可以通过举例得出
		else return false;
	}
	father[fy]=fx;
	rank[fy]=(rank[x]-rank[y]+type+3)%3;		// 与上式不同 需仔细归纳
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,k;
	int sum,i;
	int d,x,y;
	scanf("%d %d",&n,&k);
	//cin>>n>>k;
	Init(n);
	sum=0;
	for(i=0;i<k;i++)
	{
		scanf("%d %d %d",&d,&x,&y);
		//cin>>d>>x>>y;					//用cin会超时
		if(x>n || y>n ||(x==y && d==2))
			sum++;
		else if(Union(x,y,d-1))			//传d-1 方便关系式的表达
			sum++;
	}
	printf("%d\n",sum);
	return 0;
}
