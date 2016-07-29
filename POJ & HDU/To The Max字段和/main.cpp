#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 105
using namespace std;

int arr[M][M];

int main()
{
    int n, tmp;
    while(scanf("%d", &n) != EOF)
    {
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &tmp);
                arr[i][j] += arr[i][j-1] + tmp;///第i行前j个数的和
            }
        int mx = -12800;
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
            {
                int sum = 0;
                for(int k = 1; k <= n; k++)
                {
                    if(sum < 0) sum = 0;
                    sum += arr[k][j] - arr[k][i-1];///把i~j的和压缩成一维，类似一维字段和做i*j次
                    if(sum > mx) mx = sum;
                }
            }
        printf("%d\n", mx);
    }
    return 0;
}
