#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int f[2020];
int dp[2020];

int main()
{
    int ca, n;
    scanf("%d", &ca);
    while(ca--)
    {
        for(int i = 1; i <= 2019; i++)
            dp[i] = -100000;
        dp[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n-1; i++)
            scanf("%d", &f[i]);
        int ans = n * f[1];///n���㶼��һ������
        for(int i = 2; i <= n-1; i++)
            f[i] -= f[1];///֮��ÿ���Ӷ�������Ҫ������ԭ����һ���ȵ�Ȩֵ
        for(int i = 1; i <= n-2; i++)
        {
            for(int j = i; j <= n-2; j++)
            {
                dp[j] = max(dp[j], dp[j-i]+f[i+1]);///������i���ȣ�������1���ȵ�ȨֵȻ������i+1��Ȩֵ
            }
        }
        printf("%d\n", ans + dp[n-2]);
    }
    return 0;
}
