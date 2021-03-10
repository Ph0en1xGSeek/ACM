#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


int main()
{
    int ca, cc = 1;
    long long num;
    long long ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%I64d", &num);
        ans = (num+2) * (num-1) / 2;
        printf("Case #%d: %I64d\n", cc++, ans);
    }
    return 0;
}
