#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double h1, t1, h2, t2;
    while(~scanf("%lf%lf%lf%lf", &h1, &t1, &h2, &t2))
    {
        double tmp = sqrt(h1/h2);
        double ans = (tmp*t2 - t1) / (tmp -1);
        printf("%.6lf\n", ans);
    }
    return 0;
}
