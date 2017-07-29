#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 3000010

using namespace std;

long long phi[M];

void init()
{
    for(int i = 0; i <= M; i++)
        phi[i] = i;
    for(int i = 2; i <= M; i++)
        if(phi[i] == i)
        {
            for(int j = i; j <= M; j += i)
                phi[j] = phi[j]/i*(i-1);///若是质数就会变成i-1
        }
}

int main()
{
    init();
    int a, b;
    long long ans;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        ans = 0;
        for(int i = a; i <= b; i++)
            ans += phi[i];
        printf("%lld\n", ans);
    }
    return 0;
}
