#include<cstdio>
#include<cstring>
using namespace std;

int n,c[100001];//��״��������Ͻ����������Ԫ��֮��

int lowbit(int x)
{
    return x & (-x);
}

void update(int bit,int num)
{
    while(bit<=n)
    {
        c[bit]+=num;
        bit+=lowbit(bit);//�Ѷ��������ұߵ�1��λ���0�������ϼ�
    }
}

int getsum(int t)//��1λ����iλ���ۼӺͣ�
{
    int s=0;
    while(t>0)
    {
        s+=c[t];
        t-=lowbit(t);//c[t - lowbit(t)] ����ǰһ�������޽����ĵ㣬���Ѷ��������ұߵ�1���0
    }
    return s;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        int i,a,b;
        memset(c,0,sizeof(c));
        for(i=1;i<=n;++i)
        {
            scanf("%d%d",&a,&b);
            update(a,1);
            update(b+1,-1);//��˵�+1 �Ҷ˵�-1 ÿһλ�������ǰһλ�Ĳ�ӵ�һλ�ۼӵ���iλ�����ǵ�iλ�ۼӵĴ���
        }
        printf("%d",getsum(1));
        for(i=2;i<=n;++i)
            printf(" %d",getsum(i));
        printf("\n");
    }
    return 0;
}
