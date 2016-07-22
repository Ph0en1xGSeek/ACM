#include <iostream>

using namespace std;

int num[10];

void CompletePack( int price,int half, int f[])//完全背包
{
      for(int i= price; i <= half; i++)
           f[i] = max(f[i], f[i-price] + price);
}

void ZeroOnePack(int price, int num, int f[], int half)//01背包
{
        int t = num * price;
        for(int i = half; i >= t; i--)
           f[i] = max(f[i], f[i-t] + t);
}

int DP(int half)
{
    int f[120001] = {0};
     for(int i = 1; i <= 6; i++)
     {

          if(i*num[i] >= half)
               CompletePack(i, half, f);
          else
          {
                 int k=1;
                 while(k < num[i]) //2进制法
                 {
                      ZeroOnePack(i, k, f, half);
                      num[i]=num[i]-k;
                      k *= 2;
                 }
                 ZeroOnePack(i, num[i], f, half);
          }
     }
     return f[half];
}


int main()
{
    int ca = 1;
    while(1)
    {
        int tot = 0;
        for(int i = 1; i <= 6; i++)
        {
            cin >> num[i];
            tot += i * num[i];
        }
        if(tot == 0)
            break;
        cout << "Collection #" << ca++ << ':' << endl;
        if(tot % 2 != 0)
             cout << "Can't be divided." << endl;
        else
        {
            if(DP(tot / 2) == tot / 2)
                cout << "Can be divided." << endl;
            else
                cout << "Can't be divided." << endl;
        }
        cout << endl;
    }
    return 0;
}
