#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca;
    int a, b, na, nb;
    int ans1, ans2;
    int tmp;
    int nans;
    scanf("%d", &ca);
    for(int i = 0; i < ca; i++)
    {
        nans = na = nb = 0;
        scanf("%d%d", &a, &b);
        ans1 = a + b;
        while(a > 0)
        {
            na = na * 10 + a % 10;
            a /= 10;
        }

        while(b > 0)
        {
            nb = nb * 10 + b % 10;
            b /= 10;
        }
        tmp = ans1;
        while(ans1 > 0)
        {
            nans = 10 * nans + ans1 % 10;
            ans1 /= 10;
        }

        ans2 = na + nb;

        if(nans == ans2)
            printf("%d\n", tmp);
        else
            printf("NO\n");

    }
    return 0;
}
