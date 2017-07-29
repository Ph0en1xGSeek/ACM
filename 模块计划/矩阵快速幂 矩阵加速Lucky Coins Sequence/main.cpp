#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void mul(int a[][4], int b[][4])//矩阵幂取模
{
    int t[4][4] = {{0}};
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            for(int k = 1; k <= 3; k++)
                t[i][j] += (a[i][k]*b[k][j]%10007);
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            a[i][j] = t[i][j];
}

int main()
{
    int n;
    int tmp[4][4], res[4][4];
    int a[5] = {0,0,0,2,6};
    while(scanf("%d", &n) != EOF)
    {
        if(n <= 4)
            printf("%d\n", a[n]);
        else
        {
            memset(res, 0, sizeof(res));
            tmp[1][1] = tmp[1][2] = tmp[1][3] = tmp[2][1] = 1;
            tmp[2][2] = tmp[2][3] = tmp[3][1] = tmp[3][2] = 0;
            tmp[3][3] = 2;
            res[1][1] = res[2][2] = res[3][3] = 1;
            n-=4;
            while(n > 0)//矩阵快速幂
            {
                if(n&1)
                {
                    mul(res, tmp);
                    n--;
                }
                else
                {
                    mul(tmp, tmp);
                    n >>= 1;
                }
            }
            printf("%d\n", (res[1][1]*6 + res[1][2]*2 + res[1][3]*8)%10007);
        }
    }
    return 0;
}
