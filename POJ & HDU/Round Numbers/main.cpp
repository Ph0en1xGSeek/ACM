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
    while(n > 0)///��1~lenλ���Ŵ��������
    {
        bit[++len] = n%2;
        n >>= 1;
    }
    int sum = 0;
    for(int i = 1; i <= len-1; i++)///ö��λ����nС����1~len-1λ���ǵ�һ��1
        for(int j = (i+1)/2; j <= i-1; j++)///��һλһ����1��
            sum += c[i-1][j];///ʣ��i-1λ0Ҫ��1��
    int one = 1, zero = 0;///��ǰ01�ĸ���
    for(int i = len-1; i ; i--)
    {
        if(bit[i])///�����λ��1
        {
            zero++;///�����λ�ĳ�0
            for(int j = max(0, (len+1)/2-zero); j < i; j++)///Ȼ���ʣ��i-1λͳ��
                sum += c[i-1][j];
            zero--;///ͳ�����Ҫ�Ļ���
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
