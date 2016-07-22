#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void mul(int a[][2], int b[][2])//矩阵幂取模
{
    int t[2][2] = {{0}};
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                t[i][j] = (t[i][j] + (a[i][k]*b[k][j])) % 10000;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            a[i][j] = t[i][j];
}

void pow(int a[][2], int b[][2], int n)//矩阵快速幂
{
    while(n > 0)
    {
        if(n & 1)
        {
            mul(a, b);
        }
        mul(b, b);
        n >>= 1;

    }
}

int main()
{
    int tmp[2][2], res[2][2];
    int num;
    while(scanf("%d", &num) && num != -1)
    {
        if(num == 0)
            printf("0\n");
        else
        {
            memset(res, 0, sizeof(res));
            memset(tmp, 0, sizeof(tmp));
            tmp[0][0] = tmp[1][0] = tmp[0][1] = 1;
            res[0][0] = res[1][1] = 1;
            pow(res, tmp, num);
            printf("%d\n", res[0][1]);
        }
    }
    return 0;
}
