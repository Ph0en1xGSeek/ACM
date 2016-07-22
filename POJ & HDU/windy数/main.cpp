#include <cstdio>
#include <numeric>
#include <cstring>
#include <cmath>
using namespace std;

int dp[15][10];//dp[i][j] 长度为i+1的最高位为j的数里有多少个windy
//dp预处理出来
void DP()
{
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i < 10 ; i++ )
        dp[0][i] = 1;
    for(int i = 1 ; i < 10 ; i++ )
        for(int j = 0 ; j < 10 ; j++)
            for(int k = 0 ; k < 10 ; k++)
                if(abs(j-k)>1)dp[i][j]+=dp[i-1][k];
}
int find(int n)
{
    int ans = 0;
    char s[15];
    sprintf(s,"%d",n);
    int len = strlen(s);
    //对于第一行区间的求解
    for(int i = 0; s[i+1]; i++)
        ans += accumulate(dp[i]+1,dp[i]+10,0);
    //对于第二行直到最后的求解,i的条件判断是对前缀的判断，j的起点也根据是否是第一位而有所不同
    for(int i = 0; s[i] && (i<2 || abs(s[i-1]-s[i-2])>1); i++)
        for(int j = !i ? 1 : 0 ; j < s[i]-'0' ; j++)
            ans += dp[len-i-1][j] * ( !i || (abs(j-s[i-1]+'0')>1));
    return ans;
}


int main()
{
    int a,b;
    DP();
    while(scanf("%d %d",&a,&b)==2)
    {
        printf("%d\n",find(b+1)-find(a));
    }
    return 0;
}
