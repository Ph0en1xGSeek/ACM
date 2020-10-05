/**数学推导+结束条件判定**/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int ca, cc = 1;
    long long x, y;
    int ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 1;
        scanf("%I64d%I64d", &x, &y);
        while(x != y)
        {
            if(x > y)
                swap(x, y);
            long long gcd = __gcd(x, y);
            if(x*y % (gcd + x))
                break;
            long long z = x*y / (gcd + x);
            if(z < x || z >= y || z%x != 0 || z%(y-z) != 0)
                break;
            ans++;
            y -= z;
        }
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
