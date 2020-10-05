#include <cstdio>
#include <numeric>
#include <cstring>
#include <cmath>
using namespace std;

int dp[15][10];//dp[i][j] ����Ϊi+1�����λΪj�������ж��ٸ�windy
//dpԤ�������
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
    //���ڵ�һ����������
    for(int i = 0; s[i+1]; i++)
        ans += accumulate(dp[i]+1,dp[i]+10,0);
    //���ڵڶ���ֱ���������,i�������ж��Ƕ�ǰ׺���жϣ�j�����Ҳ�����Ƿ��ǵ�һλ��������ͬ
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
