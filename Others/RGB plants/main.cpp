#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void mul(long long a[][4], long long b[][4])//矩阵幂取模
{
    long long t[4][4] = {{0}};
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            for(int k = 1; k <= 3; k++)
                t[i][j] = (t[i][j]+a[i][k]*b[k][j]%1000000007)%1000000007;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            a[i][j] = t[i][j];
}

int main()
{
    int ca, n;
    long long ans;
    long long tmp[4][4], res[4][4], source[4][4] = {0,0,0,0,0,1,4,7,0,2,5,8,0,3,6,9};
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &n);
        memset(res, 0, sizeof(res));
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++)
                tmp[i][j] = source[i][j];
        res[1][1] = res[2][2] = res[3][3] = 1;
        n--;
        if(n == 0)
        {
            printf("3\n");
            continue;
        }
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
        for(int i = 1; i<= 3; i++)
            for(int j = 1; j <= 3; j++)
                ans = (ans + res[i][j]) % 1000000007;
        printf("%I64d\n", ans);
    }
    return 0;
}
