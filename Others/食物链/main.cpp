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
		rank[x]=(rank[x]+rank[father[x]])%3;	//ע�� ��rank[father[x]]������rank[fx]
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
		if((rank[y]-rank[x]+3)%3!=type)return true;		//�����ϵ����ͨ�������ó�
		else return false;
	}
	father[fy]=fx;
	rank[fy]=(rank[x]-rank[y]+type+3)%3;		// ����ʽ��ͬ ����ϸ����
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
		//cin>>d>>x>>y;					//��cin�ᳬʱ
		if(x>n || y>n ||(x==y && d==2))
			sum++;
		else if(Union(x,y,d-1))			//��d-1 �����ϵʽ�ı��
			sum++;
	}
	printf("%d\n",sum);
	return 0;
}
