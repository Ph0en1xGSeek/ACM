#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct node
{
    double x, y;
}point[1005];

double square(node* p, int n)
{
    double ans = 0;
    for(int i = 1; i <= n; i++)//i%nÒ»¸ö»·
        ans += p[i-1].x * p[i%n].y - p[i%n].x * p[i-1].y;
    return fabs(ans / 2.0);
}

int main()
{
    int num;
    while(scanf("%d", &num), num)
    {
        for(int i = 0; i < num; i++)
            scanf("%lf%lf", &point[i].x, &point[i].y);
        printf("%d\n", (int)(square(point, num)+0.5));
    }
    return 0;
}
