#include <iostream>
#include <stdio.h>
#define M 105

using namespace std;

struct point
{
    double x, y;
}u[M], v[M];

double chacheng(point p1, point p2, point p)//pp1 X pp2叉乘
{
    return (p1.x - p.x)*(p2.y - p.y) - (p2.x - p.x)*(p1.y - p.y);
}

bool onSegment(point p1, point p2, point p)//若p在直线 p1 p2上 是否在线段p1p2上
{
    double mx = max(p1.x, p2.x);
    double mi = min(p1.x, p2.x);
    if(p.x >= mi && p.x <= mx)
        return true;
    else
        return false;
}

bool isBanana(point p1, point p2, point p3, point p4)//是否相交
{
    double d1 = chacheng(p1, p2, p3);
    double d2 = chacheng(p1, p2, p4);
    double d3 = chacheng(p3, p4, p1);
    double d4 = chacheng(p3, p4, p2);
    if(d1*d2 < 0 && d3*d4 < 0)//相互跨越
        return true;
    else if(d1 == 0 && onSegment(p1, p2, p3))
        return true;
    else if(d2 == 0 && onSegment(p1, p2, p4))
        return true;
    else if(d3 == 0 && onSegment(p3, p4, p1))
        return true;
    else if(d4 == 0 && onSegment(p3, p4, p2))
        return true;

    return false;
}

int main()
{
    int num, ans;
    while(scanf("%d", &num) && num != 0)
    {
        ans = 0;
        for(int i = 0; i < num ; i++)
            scanf("%lf %lf %lf %lf", &u[i].x, &u[i].y, &v[i].x, &v[i].y);
        for(int i = 0; i < num-1; i++)
            for(int j = i+1; j < num ; j++)
                if(isBanana(u[i], v[i], u[j], v[j]))
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}
