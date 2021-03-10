#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>


using namespace std;

int biSearch(int l, int r, int num)
{
    double ang = 360.0 / (r+2);
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if(ang * mid < 1.0*num)
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main() {

    int n, a;
    while (~scanf("%d%d", &n, &a))
    {
        int tmp = biSearch(1, n-2, a<<1);
        int ans = tmp;
        double soluAns = fabs(tmp*(360.0/n) - a*2.0);
        if(tmp-1 > 0 && soluAns > fabs((tmp-1)*(360.0/n) - a*2.0))
        {
            soluAns = fabs((tmp-1)*(360.0/n) - a*2.0);
            ans = (tmp-1);
        }

        if(tmp+1 <= n-2 && soluAns > fabs((tmp+1)*(360.0/n) - a*2.0))
        {
            soluAns = fabs((tmp+1)*(360.0/n) - a*2.0);
            ans = (tmp+1);
        }

        printf("2 1 %d\n", 2 + ans);
    }
    return 0;
}