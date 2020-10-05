#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long l, r;
    while(~scanf("%I64d%I64d", &l, &r))
    {
        if(l == 0)
        {
            if(r <= 1) puts("0");
            else printf("%I64d\n", (r+1)/2);
        }
        else if(l == 1)
        {
            if(r == 1) puts("0");
            else printf("%I64d\n", (r+1)/2);
        }
        else if(l == 2)
        {
            if(r == 2) puts("1");
            else printf("%I64d\n", (r-l-2)/2+2);
        }
        else
        {
            long long ans = 2;
            ans += (r-l-2)/2;
            ans = max(ans, 2ll);
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
