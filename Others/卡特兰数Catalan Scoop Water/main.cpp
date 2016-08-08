#include <iostream>
#include <stdio.h>
#include <string.h>
#define mod 1000000007

using namespace std;

int main()
{
    long long c[10005];
    memset(c, 0, sizeof(c));
    c[0] = c[1] = 1;
    for(int i = 2; i <= 10000; i++)
    {
        for(int j = 0; j < i; j++)
            c[i] = ((c[j]*c[i-j-1]%mod)+c[i])%mod;
    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%lld\n", c[n]);
    }
    return 0;
}
