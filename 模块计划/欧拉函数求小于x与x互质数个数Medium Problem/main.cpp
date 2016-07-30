/**ŷ����ʽ��phi(x) = (p1-1)/p1*(p2-1)/p2....*(pn-1)/pn * x
pi��С��x������**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#define N 10005


int phi[N],prime[N];
int dp[N];

void init()
{
    int i,j;
    memset(prime, 0, sizeof(prime));
    memset(phi, 0, sizeof(phi));
    prime[0]= prime[1] = 1;
    for(i=2; i*i < N; i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<=N;j+=i)
            {
                prime[j]=1;
            }
        }
    }     //��������N�ڵ���������
    for(i=1;i<N;i++)
    {
        phi[i]=i;
    }
    for(i=2;i<N;i++)
    {
        if(!prime[i])
        {
            phi[i] = i-1;
            for(j=i+i;j<N;j+=i)
            {
                phi[j] = phi[j]/i*(i-1);     //�˴�ע����/i��*��i-1)������Χ�ϴ�ʱ�����
            }
        }
    }
    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i < N; i++)
        dp[i] = phi[i] + dp[i-1];
}


int main()
{
    init();
    int ca, c, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &c, &num);
        printf("%d %d\n", c, dp[num]);
    }


    return 0;
}
