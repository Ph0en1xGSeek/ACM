#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 99999999

int map[15][15];
int dp[(1<<12)+5][12];

int main()
{
    int i,j,n,ans,k,p;
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        n++;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for (k=0;k<n;k++)
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    if (i!=j && i!=k && j!=k) map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        for (i=1;i<(1<<n);i++)
        {
            for (j=0;j<n;j++)
            {
                if (dp[i][j]==-1) continue;
                for (k=1;k<n;k++)
                {
                    if ((i & (1<<k))!=0) continue;
                    p=(i | (1<<k));
                    if (dp[p][k]==-1) dp[p][k]=dp[i][j]+map[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+map[j][k]);
                }
            }
        }
        ans=INF;
        for (i=1;i<n;i++)
        {
            if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+map[i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
