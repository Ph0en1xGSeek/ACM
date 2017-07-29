#include <iostream>
using namespace std;
//此程序为将一个整数分解为任意个个整数的方法

const int N=120;
int f[N+1],a[N+1],g[N+1];
int i,j,k,n,m;

int main()
{
    while(cin>>n)
    {
        for (i = 0; i <= n; ++i) // 0 1 2 3 4 5 6
            f[i]=1;

        for (i = 2; i <= n; ++i) // f[]保存前面i-1个因子相乘的结果 i = 1上面的循环初始化过了
        {
            for (j = 0; j <= n; ++j)
                a[j]=0;
            j=0;
            while (j <= n)   // a[j]=k表示的是k*(x^j),a[]数组表示母函数的第i个因子
            {
                a[j]=1;
                j+=i;// * (0 2 4 6 8) * (0 3 6 9 12) * (0 4 8 12)
            }

            for (j = 0; j <= n; ++j) // 暂存f[]*a[]的结果
                g[j] = 0;

            for (j = 0; j <= n; ++j)
                for(k = 0; k+j <= n; ++k)
                    g[j+k] += f[j]*a[k]; // 为了不让f[]的值因为改动而影响以后的值，用g[]来暂存结果
                //j次方和k次方相乘改变j+k次方系数                        // 两个母函数的因子相乘，若f[j]，a[k]分别属于第1、2个因子，那么f[j]*(x^j)*a[k]*(x^k)==f[j]*a[k]*(x^(j+k))
                                        // 故有g[j+k]+=f[j]*a[k]
            for (j = 0; j <= n; ++j)
                f[j] = g[j];
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
