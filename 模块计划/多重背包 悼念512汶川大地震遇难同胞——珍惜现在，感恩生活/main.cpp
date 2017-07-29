#include <iostream>
using namespace std;

int price[124], num[124], weight[124];

void CompletePack( int price,int f[],int money,int weight )//完全背包
{
      for(int i=price; i<=money; i++ )
           f[i] = max(f[i], f[i-price] + weight);
}

void ZeroOnePack( int price,int num,int f[],int money,int weight )//01背包
{
        int t = num*weight,tt = num*price;
        for( int i=money; i>=tt;i--)
           f[i] = max(f[i], f[i-tt]+t);
}

int DP(int number ,int money)
{
    int f[124] = {0};
     for(int i = 1; i <= number; i++)
     {

          if(price[i]*num[i] >= money)//肯定用不完的转为完全背包
               CompletePack(price[i], f, money, weight[i]);
          else
          {
                 int k=1;
                 while(k < num[i]) //2进制法
                 {
                      ZeroOnePack( price[i],k,f,money,weight[i] );
                      num[i]=num[i]-k;
                      k *= 2;
                 }
                 ZeroOnePack( price[i],num[i],f,money,weight[i] );
          }
     }
     return f[money];
}

int main()
{
    int money, n, number;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> money >> number;
        for( int j=1; j<=number ; j++ )
        {
           cin >> price[j] >> weight[j] >> num[j];
        }
        cout << DP(number, money) << endl;
    }
    return 0;
}
