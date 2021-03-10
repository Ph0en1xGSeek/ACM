#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    long long i,j,m,dp[12][12],sum[12],c[12][12];
    int k,T,n;
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    memset(c,0,sizeof(c));
    dp[1][1]=1;
    for(i=0;i<12;i++)
        c[i][0]=c[i][i]=1;//组合C的递推
    for(i=2;i<12;i++)
        for(j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    sum[1]=1;
    for(i=2;i<12;i++)
        for(j=1;j<=i;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*j;//dp[i][j]表示的i个数组成j个集合的个数。已经全排列
            sum[i]+=dp[i][j];
        }
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        scanf("%d",&n);
        for(i=1,m=0;i<=n;i++)
            m+=c[n][i]*sum[i];
        printf("%d %d %lld\n",k,n,m);
    }
    return 0;
}
