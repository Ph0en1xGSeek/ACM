#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

using namespace std;

struct circle
{
    double x, y, r;
}c[2];

double dis(circle r1, circle r2)
{
    return sqrt((r1.x-r2.x)*(r1.x-r2.x) + (r1.y-r2.y)*(r1.y-r2.y));
}

double solve(circle r1, circle r2)
{
    double d = dis(r1, r2);
    if(d >= r1.r + r2.r)
        return 0;
    if(d <= fabs(r1.r - r2.r))
    {
        double ra = min(r1.r, r2.r);
        return PI * ra * ra;
    }
    double angle1 = acos((r1.r * r1.r + d * d - r2.r * r2.r) / 2.0 / r1.r / d);
    double angle2 = acos((r2.r * r2.r + d * d - r1.r * r1.r) / 2.0 / r2.r / d);
    double ans = angle1 * r1.r * r1.r + angle2 * r2.r * r2.r - d * r1.r * sin(angle1);
    return ans;
}

int main()
{
    scanf("%lf %lf %lf", &c[0].x, &c[0].y, &c[0].r);
    scanf("%lf %lf %lf", &c[1].x, &c[1].y, &c[1].r);
    printf("%.3f\n", solve(c[0], c[1]));
    return 0;
}
