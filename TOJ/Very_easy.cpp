#include <iostream>
#include <cmath>
using namespace std;
#define N 3300
#define M 30000
#include <stdio.h>
#include <cstring>

int p[M+2]={0};
int prime[N+2], t = 1;
int num[N+2];

void getprime()   //��ǰ90������
{
    for(int l = 2; l < M; l++)
    {
        if(!p[l])
        {
            for(int q = l<<1; q < M; q += l)
                p[q] = 1;
            prime[t++] = l;
        }
    }
}

int cal(int n,int p)      //��N�Ľ׳˺�������M�Ĵ���
{
   if(p > n)
      return 0;
   else
      return n/p + cal(n/p, p);//1��n�������к���һ��2 ����2������ֱ��Ϊ��
}

int main()
{
   int i, j, k, n, tmp;
   getprime();
   while(cin >> n >> k)
   {
        memset(num, 0, sizeof(num));
        tmp = k;
        k = min(k, n-k);
        for(i = 1; prime[i] <= n && i < t; i++)
            num[i] = (cal(n, prime[i])-cal(k, prime[i])-cal(n-k, prime[i]));//A/BԼ����������
        printf("%dC%d = ", n, tmp);
        for(j = 1; j < i; j++)
            if(num[j] > 0)
                break;
        printf("%d", prime[j]);
        for(int kk = 1; kk < num[j]; kk++)
            printf(" * %d", prime[j]);
        for(int kk = j+1; kk < i; kk++)
        {
            for(j = 0; j < num[kk]; j++)
                printf(" * %d", prime[kk]);
        }
        printf("\n");
    }
    return 0;
}
