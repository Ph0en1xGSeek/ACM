#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool dp[100005][2];///dp[i][0]Ϊi��ʯ�ӿ�����ż�����Ƴ���
                    ///dp[i][1]Ϊ������
int arr[10005];

int main()
{
    int n, m, ans;
    while(scanf("%d%d", &n, &m) && n)
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        dp[arr[0]][1] = true;///�����0����
        for(int i = 1; i < n; i++)
        {
            for(int j = m; j > arr[i]; j--)///����,����01��������άģ����ά�����ܵ�ǰ���ڸ�������Ӱ��
            {
                if(dp[j-arr[i]][1])
                    dp[j][0] = true;
                if(dp[j-arr[i]][0])
                    dp[j][1] = true;
            }
            dp[arr[i]][1] = true;///Ϊ�˲�Ӱ�죬�������Լ�
        }
        for(int i = 1; i <= m; i++)
            if(dp[i][1] && !dp[i][0])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
