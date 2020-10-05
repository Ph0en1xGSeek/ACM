#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    double a, v1, v2;
    while(scanf("%lf%lf%lf",&a, &v1, &v2) != EOF)
    {
        double ans = 0;
        if(a == 0 || v1 > v2)
        {
            if(v1 > v2)
                ans = a * v1 / ((v1*v1)-(v2*v2));
            printf("%.10f\n", ans);
        }
        else
        {
            printf("Infinity\n");
        }
    }
    return 0;
}
