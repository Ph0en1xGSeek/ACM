#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

long long c[37][37];

void init()
{
    for(int i = 1; i <= 36; i++)
        c[i][0] = c[i][i] = 1;
    for(int i = 2; i <= 36; i++)
        for(int j = 1; j < i; j++){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
}

int main()
{
    init();
    int ca, caa, num;
    long long ans ;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d%d", &caa, &num);
        num >>= 1;
        int two = num >> 1;
        int one = num & 1;
        while(two >= one)
        {
            ans += c[two+one][one]*c[two+one][one];
            one += 2;
            two--;
        }
        printf("%d %lld\n", caa, ans);
    }
    return 0;
}
