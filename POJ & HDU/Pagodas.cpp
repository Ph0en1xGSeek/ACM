#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, num, a, b;
    int cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d%d", &num, &a, &b);
        int gcd = __gcd(a, b);
        int n = num / gcd;
        if(n&1)
            printf("Case #%d: Yuwgna\n", cc++);
        else
            printf("Case #%d: Iaka\n", cc++);
    }
    return 0;
}
