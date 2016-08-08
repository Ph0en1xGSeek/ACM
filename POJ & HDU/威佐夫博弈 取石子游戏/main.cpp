#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int a, b, mi, mx;
    while(~scanf("%d%d", &a, &b))
    {
        mi = min(a, b);
        mx = max(a, b);
        int k = mx - mi;
        int tmp = (int)(k * (1.0 + sqrt(5)) / 2.0);
        if(tmp == mi)
            puts("0");
        else
            puts("1");
    }
    return 0;
}
