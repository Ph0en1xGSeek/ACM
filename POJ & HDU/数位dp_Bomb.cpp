#include <iostream>
#define ll long long
#include <cstdio>
#include <cstring>

using namespace std;
ll dp[20][3];///0���쳣�����У� 1��һλΪ9�� 2����49
int arr[20];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 20; i++)
    {
        ///����������=֮ǰ��������������һ����-4+��ͷΪ9������������
        dp[i][0] = 10 * dp[i-1][0] - dp[i-1][1];
        ///��9
        dp[i][1] = dp[i-1][0];
        ///4+9��ͷ���������Ͳ���������������һ��
        dp[i][2] = dp[i-1][1] + 10 * dp[i-1][2];
    }
    int ca;
    ll num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%lld", &num);
        num++;
        int counts = 0;
        while(num)
        {
            arr[++counts] = num % 10;
            num /= 10;
        }
        arr[counts + 1] = 0;
        int flag = 0;
        ll ans = 0;///��49�ĸ���
        for(int i = counts; i >= 1; i--)
        {
            ///0~arr[i]-1��ͷ�Ķ�����������i-1λ
            ans += dp[i-1][2] * arr[i];
            ///��λ�Ѿ�����49�ˣ���ʱ��ʹ��û��49��ҲҪ�����ȥ
            if(flag == 1)
                ans += dp[i-1][0] * arr[i];
            ///��һ��49Ҫ����9��ͷ�ĺϷ�����
            else if(arr[i] > 4)
            {
                ans += dp[i-1][1];
            }
            ///��λ����49
            if(arr[i] == 9 && arr[i+1] == 4)
            {
                flag = 1;
            }

        }
        printf("%lld\n", ans);

    }


    return 0;
}
