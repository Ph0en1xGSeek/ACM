#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int x, d, k;
    int v[100010];
    int ca, n, num;
    scanf("%d", &ca);
    double ans, c, t;
    while(ca--)
    {
        scanf("%d%lf", &n, &c);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &v[i], &x, &d);
        }
        sort(v, v+n);
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%lf%d", &t, &k);
            double v0 = (double)v[k-1];
            ans = sqrt(2.0*c*t + v0*v0);
            printf("%.3lf\n", ans);
        }
    }
    return 0;
}
