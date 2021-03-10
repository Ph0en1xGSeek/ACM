#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 1000010
#define INF 0x7fffffff

using namespace std;

int arr[N];
int dp[N];///��i��ѭ�� ��j������Ϊ���һ��������һ��Ԫ�ص����ֵ
int mTo[N];///ǰj-1�����ֳ�i-1������ֵ

int main()
{
    int m, n;
    int tmp;
    while(~scanf("%d%d", &m, &n))
    {
        memset(dp, 0, sizeof(dp));
        memset(mTo, 0, sizeof(mTo));
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for(int i = 1; i <= m; i++)
        {
            tmp = -INF;
            for(int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j-1]+arr[j], mTo[j-1]+arr[j]);
                mTo[j-1] = tmp;
                tmp = max(tmp, dp[j]);
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}
