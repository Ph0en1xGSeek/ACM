#include<cstdio>
#include<cstring>
using namespace std;

int n,c[100001];//树状数组所管辖区域内所有元素之和

int lowbit(int x)
{
    return x & (-x);
}

void update(int bit,int num)
{
    while(bit<=n)
    {
        c[bit]+=num;
        bit+=lowbit(bit);//把二进制最右边的1那位变成0，即找上级
    }
}

int getsum(int t)//第1位到第i位的累加和，
{
    int s=0;
    while(t>0)
    {
        s+=c[t];
        t-=lowbit(t);//c[t - lowbit(t)] 是找前一个和他无交集的点，即把二进制最右边的1变成0
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
            update(b+1,-1);//左端点+1 右端点-1 每一位存的是与前一位的差，从第一位累加到第i位，就是第i位累加的次数
        }
        printf("%d",getsum(1));
        for(i=2;i<=n;++i)
            printf(" %d",getsum(i));
        printf("\n");
    }
    return 0;
}
