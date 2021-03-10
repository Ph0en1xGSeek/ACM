#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    int x4, x2, x1;
    int tmp;
    int sum;
    while(~scanf("%d%d", &n, &k))
    {
        sum = 0;
        x4 = x2 = x1 = 0;
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &tmp);
            sum += tmp;
            x4 += tmp / 4;
            tmp %= 4;
            x2 += tmp / 2;
            x1 += tmp % 2;
        }
        if(sum + x1 > n*8)
        {
            printf("NO\n");
        }
        else if(x4 + x1 >= n)
        {
            printf("YES\n");
        }
        else
        {
            tmp = n - x4 - x1;
            x2 -= n - x4 + 2*n;
            if(x2 <= 0)
                printf("YES\n");
            else
            {
                x2 *= 2;
                if(x2 <= tmp)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
