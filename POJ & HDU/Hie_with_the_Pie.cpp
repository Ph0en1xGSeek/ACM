#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 99999999

int mp[15][15];
int dp[(1<<12)+5][12];///dp[i][j]当前在j点已经走过i状态表示的点

int main()
{
    int i,j,n,ans,k,p;
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        n++;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &mp[i][j]);
            }
        }
        ///Floyd
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (i!=j && i!=k && j!=k)
                        mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        for (i = 1; i < (1<<n); i++)///枚举已走过的点
        {
            for (j=0;j<n;j++)
            {
                if (dp[i][j]==-1)///j在i中没被选中（或者不联通虽然不可能）
                    continue;///或者没经过已走过的点都是-1
                for (k=1;k<n;k++)
                {
                    if ((i & (1<<k))!=0) continue;///枚举新到的点
                    p=(i | (1<<k));
                    if (dp[p][k]==-1) dp[p][k]=dp[i][j]+mp[j][k];
                    dp[p][k]=min(dp[p][k],dp[i][j]+mp[j][k]);
                }
            }
        }
        ans=INF;
        for (i = 1; i < n; i++)
        {
            if (dp[(1<<n)-1][i]>0) ans=min(ans,dp[(1<<n)-1][i]+mp[i][0]);///最后得回去
        }
        printf("%d\n",ans);
    }
    return 0;
}
