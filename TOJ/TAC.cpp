#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
double x, y;
double sq(double xx, double yy)
{
    return sqrt(pow(xx-x, 2)+pow(yy-y,2));
}

int main()
{
    int t;
    double r;
    double m, n, m2, n2, m3, n3;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf%lf%lf", &r, &x, &y);
        scanf("%lf%lf%lf%lf%lf%lf", &m, &n, &m2, &n2, &m3, &n3);

        if(sq(m,n) <= r && sq(m2, n2) <= r && sq(m3, n3) <= r)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
