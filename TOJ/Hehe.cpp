#include <iostream>
#include <cstdio>
#define mod 10007
#include <cstring>

using namespace std;
int dp[10088];//��������he�������

void init()
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < 10088; i++)
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    //���һ���ӵ�he�����򲻲��룬�����γ�쳲�����
}

int main()
{
    int ca, counts, ans;
    init();
    char str[10088];
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        ans = 1, counts = 0;
        scanf("%s", str);
        int len = strlen(str);
        for(int j = 0; j < len;)
        {
            if(str[j] == 'h' && str[j+1] == 'e')
            {
                counts++;
                j += 2;
            }
            else
            {
                ans =  (ans * dp[counts])%mod;
                counts = 0;
                j++;
            }
        }
        ans =  (ans * dp[counts])%mod;
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
