#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

int main()
{
    int a[10], b[10];
    int ca, num, cc = 1;
    scanf("%d", &ca);
    int zi, mu;
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= num; i++)
            scanf("%d", &b[i]);
        int gcd = __gcd(a[num], b[num]);
        zi = b[num]/gcd;
        mu = a[num]/gcd;
        for(int i = num-1; i >= 1; i--)
        {
            zi += (a[i] * mu);
            mu *= b[i];
            gcd = __gcd(zi, mu);
            zi /= gcd;
            mu /= gcd;
            swap(zi, mu);
        }
        printf("Case #%d: %d %d\n", cc++, zi, mu);
    }
    return 0;
}
