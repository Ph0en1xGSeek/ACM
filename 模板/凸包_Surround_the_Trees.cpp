#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define N 110
#define eps 1e-8

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double xx, double yy):x(xx), y(yy){}
    point operator-(point a)///向量叉积
    {
        return point(x-a.x, y-a.y);
    }
    double operator*(point a)///向量叉积
    {
        return x*a.y - y*a.x;
    }
    bool operator<(const point a) const
    {
        if(fabs(x-a.x) < eps)
            return y < a.y;
        return x < a.x;
    }
    double len()
    {
        return sqrt(x*x + y*y);
    }
}s[N], p[N];///s为凸包点集

double cp(point a, point b, point o)
{
    return ((a-o)*(b-o));
}

void Convex(point *p, int &n)///n在求完凸包后会成为凸包的点数
{
    ///sort(p, p+n);
    int top, m;
    s[0] = p[0], s[1] = p[1];
    top = 1;
    for(int i = 2; i < n; i++)
    {
        while(top > 0 && cp(p[i], s[top], s[top-1]) >= 0)
            top--;
        s[++top] = p[i];
    }
    m = top;///半个凸包
    s[++top] = p[n-2];
    for(int i = n-3; i >= 0; i--)
    {
        while(top > 0 && cp(p[i], s[top], s[top-1]) >= 0)
            top--;
        s[++top] = p[i];
    }
    top--;///第一个点重复
    n = top+1;
}

int main()
{
    int num, m;
    while(~scanf("%d", &num) && num != 0)
    {
        for(int i = 0; i < num; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p+num);
        int j = 0;
        for(int i = 1; i < num; i++)
            if(fabs(p[i].x - p[j].x) > eps || fabs(p[i].y - p[j].y) > eps)
                p[++j] = p[i];
        m = j+1;
        if(m == 0)
            puts("0.00");
        else if(m == 2)
            printf("%.2lf\n", (p[1]-p[0]).len());
        else
        {
            Convex(p, m);
            double ans = 0;
            s[m] = s[0];
            for(int i = 1; i <= m; i++)
                ans += (s[i]-s[i-1]).len();
            printf("%.2lf\n", ans);
        }
    }
    return 0;
}
