#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

using namespace std;

struct circle
{
    double x, y, r;
}c[4];

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
    double ans = angle1 * r1.r * r1.r + angle2 * r2.r *  r2.r - d * r1.r * sin(angle1);
    return ans;
}

int main()
{
    int ca, cc = 1;
    double r, R;
    double x1, y1, x2, y2;
    double ans1, ans2, ans3, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%lf%lf", &r, &R);
        c[0].r = c[1].r = r;
        c[2].r = c[3].r = R;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        c[0].x = c[2].x = x1;
        c[0].y = c[2].y = y1;
        c[1].x = c[3].x = x2;
        c[1].y = c[3].y = y2;
        ans1 = solve(c[0], c[1]);
        ans2 = solve(c[2], c[3]);
        ans3 = 2.0*solve(c[0], c[3]);
        ans = ans1 + ans2 -ans3;
        printf("Case #%d: %.6lf\n", cc++, ans);
    }
    return 0;
}
