#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int x, y, w, n;
    while(~scanf("%d %d %d %d", &x, &y, &w, &n))
    {
        int tmp = x/w+1;
        int num = n/tmp;
        int r = n%tmp;
        int tmp2;
        if(r == 0)
            tmp2 = -y-(x%w);
        else
            tmp2 = (r-1)*w;
        int ans = num*(x+y)+tmp2;
        printf("%d\n", ans);
    }
    return 0;
}
