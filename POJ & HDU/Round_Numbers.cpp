#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int c[35][35];

void init()
{
    for(int i = 0; i < 35; i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
}

int solve(int n)
{
    int len = 0, bit[35];
    while(n > 0)///从1~len位倒着存二进制数
    {
        bit[++len] = n%2;
        n >>= 1;
    }
    int sum = 0;
    for(int i = 1; i <= len-1; i++)///枚举位数比n小的数1~len-1位上是第一个1
        for(int j = (i+1)/2; j <= i-1; j++)///第一位一定是1，
            sum += c[i-1][j];///剩下i-1位0要比1多
    int one = 1, zero = 0;///当前01的个数
    for(int i = len-1; i ; i--)
    {
        if(bit[i])///如果该位是1
        {
            zero++;///则把这位改成0
            for(int j = max(0, (len+1)/2-zero); j < i; j++)///然后对剩下i-1位统计
                sum += c[i-1][j];
            zero--;///统计完后要改回来
            one++;
        }
        else
            zero++;
    }
    return sum;
}

int main()
{
    int a, b;
    init();
    while(scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d\n", solve(b+1) - solve(a));
    }
    return 0;
}
