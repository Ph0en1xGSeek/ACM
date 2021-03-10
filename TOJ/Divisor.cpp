#include <iostream>
#include <cmath>
using namespace std;
#define N 90
#define M 450

int p[M+2]={0};
int prime[N+2],l,q,t=1;

void getprime(int n)   //求前90个素数
{
    for(l = 2; l < n; l++)
    {
        if(!p[l])
        {
            for(q = l<<1; q < n; q += l)
                p[q]=1;
            prime[t]=l;
            t++;
        }
    }
}

int cal(int n,int p)      //求N的阶乘含质因数M的次数
{
   if(p > n)
      return 0;
   else
      return n/p + cal(n/p, p);//1到n所有数中含有一个2 两个2。。。直到为零
}

/*例如:20!
1.先求出20以内的素数,(2,3,5,7,11,13,17,19)
2.再求各个素数的阶数
e(2)=[20/2]+[20/4]+[20/8]+[20/16]=18;
e(3)=[20/3]+[20/9]=8;
e(5)=[20/5]=4;
...
e(19)=[20/19]=1;
所以
20!=2^18*3^8*5^4*...*19^1

解释：
2、4、6、8、10、12、14、16、18、20能被2整除
4、8、12、16、20能被4整除（即被2除一次后还能被2整除）
8、16能被8整除（即被2除两次后还能被2整除）
16能被16整除（即被2除三次后还能被2整除）
这样就得到了2的阶。其它可以依次递推。*/

int main()
{
   int i, j, k, n;
   long long m;
   getprime(M);
   while(cin >> n >> k)
   {
        k = min(k, n-k);
      for(i = 1, m = 1; prime[i] <= n, i < t; i++)
         m *= (cal(n,prime[i])-cal(k,prime[i])-cal(n-k,prime[i])+1);//A/B约数个数的求法
      cout << m << endl;
   }
   return 0;
}

/*若求A/B的约数个数，A可分解为p1^a1*p2^a2*...*pk^ak，B可分解为q1^b1*q1^b2*...*qk^bk,则A/B的约数个数
 为(a1-b1+1)*(a2-b2+1)*(a3-b3+1)...*(ak-bk+1).*/
