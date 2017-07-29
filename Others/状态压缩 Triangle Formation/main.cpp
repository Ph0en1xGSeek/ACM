#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
typedef long long LL;

int dp[1<<maxn], n;
LL a[maxn];

int main() {
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; ++i) scanf("%lld",a + i);
        sort(a,a+n);
        memset(dp,0,sizeof dp);
        int ret = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
                for(int k = j + 1; k < n; ++k)
                {
                    if(a[i] + a[j] > a[k])///�������������
                    {
                        for(int t = 0; t < (1<<n); ++t)///ö��״̬
                        {
                            if(((t>>i)&1) || ((t>>j)&1) || ((t>>k)&1))///���ⲻ�����������ߵ�״̬
                                continue;
                            int tmp = (t|(1<<i)|(1<<j)|(1<<k));///����������
                            dp[tmp] = max(dp[tmp],dp[t] + 1);///����״̬
                            ret = max(ret,dp[tmp]);
                        }
                    }
                }
        }
        printf("%d\n",ret);
    }
    return 0;
}
