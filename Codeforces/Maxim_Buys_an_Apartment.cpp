#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long n, k;
    long long mi, mx;
    while(~scanf("%I64d%I64d", &n, &k))
    {
        if(k == n)
        {
            printf("0 0\n");
            continue;
        }

        if(k == 0)
        {
            printf("0 0\n");
            continue;
        }

        mi = 1;

        if(3*k <= n)
        {
            mx = k*2;
        }
        else if(2*k <= n)
        {
            mx = (3*k - n) + 2*(n-2*k);
        }
        else
        {
            mx = n-k;
        }
        printf("%I64d %I64d\n", mi, mx);

    }
    return 0;
}
