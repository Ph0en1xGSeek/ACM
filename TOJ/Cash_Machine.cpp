#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int w[15];
int num[15];

void CompletePack(int price,int f[],int money)//完全背包
{
      for(int i=price; i<=money; i++ )
           f[i] = max(f[i], f[i-price] + price);
}

void ZeroOnePack(int price,int num,int f[],int money)//01背包
{
        int t = num*price,tt = num*price;
        for( int i=money; i>=tt;i--)
           f[i] = max(f[i], f[i-tt]+t);
}

int DP(int number ,int money)
{
    int f[100005] = {0};
     for(int i = 1; i <= number; i++)
     {

          if(w[i]*num[i] >= money)//肯定用不完的转为完全背包
               CompletePack(w[i], f, money);
          else
          {
                 int k=1;
                 while(k < num[i]) //2进制法
                 {
                      ZeroOnePack(w[i],k,f,money);
                      num[i]=num[i]-k;
                      k <<= 1;
                 }
                 ZeroOnePack(w[i],num[i],f,money);
          }
     }
     return f[money];
}

int main()
{
    int p, cash, n;
    while(scanf("%d%d", &cash, &n) != EOF)
    {
        p = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &num[i], &w[i]);
        printf("%d\n", DP(n, cash));
    }
    return 0;
}
