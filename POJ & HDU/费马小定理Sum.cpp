#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mod 1000000007

using namespace std;
char N[100010];
long long pow(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans*a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{

    while(~scanf("%s", N))
    {
        long long n = 0;
        int len = strlen(N);
        for(int i = 0; i < len; i++)
        {
            n = (n*10 + N[i] - '0')%(mod-1);
            ///费马小定理优化次幂
        }
        printf("%I64d\n", pow(2ll, n-1));
    }
    return 0;
}
