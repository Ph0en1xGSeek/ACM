#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int dp[10][3];
//dp[i][j]��i�������ֵ�λ����j����״��
//dp[i][0],��ʾ�����ڲ���������
//dp[i][1],��ʾ�����ڲ��������֣������λΪ2
//dp[i][2],��ʾ���ڲ���������

void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= 6; i++)//���999999
    {
        dp[i][0] = 9 * dp[i-1][0] - dp[i-1][1];
        //���λ���ϲ���4��9�����ֵ�״��������Ϊ���6������Ҫ��ȥǰһ�ֿ�ͷΪ2�����
        dp[i][1] = dp[i-1][0];//ֻ��2
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + 10 * dp[i-1][2];
        //�Ѿ����е�ǰ���ʲô�������ԣ������Ƿ�һ��4����������2ǰ���6
    }
}

int solve(int n)///1��n������n������������
{
    int counts = 0, tmp = n, flag = 0, arr[10], ans = 0;//ansΪ��������
    while(n)
    {
        arr[++counts] = n % 10;
        n /= 10;
    }
    arr[counts + 1] = 0;
	///ÿһ����ֻ���㵽0~arr[i]-1��ͷ�������Ȼ����һλ��Ϊarr[i]��ʼ������һλ
    for(int i = counts; i >=1; i--)
    {
        ///0~arr[i]-1��ͷ��������i-1λ��
        ans += dp[i-1][2] * arr[i];
		
		///��Ϊ���ϸ�λ�ű�ɲ����������
        if(flag)
			///��λ�Ѿ�����4��62�ˣ���������Ҫ��
            ans += dp[i-1][0] * arr[i];
        else
        {
            ///����λ����4����Ҫ����4+ i-1λ���������ɵĲ�������
            if(arr[i] > 4)
                ans += dp[i-1][0];
            if(arr[i+1] == 6 && arr[i] > 2)
                ans += dp[i][1];
            if(arr[i] > 6)
                ans += dp[i-1][1];
        }
        if(arr[i] == 4 || (arr[i+1] == 6 && arr[i] == 2))
            flag = 1;
    }
    return tmp - ans;
}

int main()
{
    int n, m;
    init();
    while(scanf("%d%d", &n, &m) && n+m)
    {
        printf("%d\n", solve(m + 1) - solve(n));
    }
    return 0;
}
