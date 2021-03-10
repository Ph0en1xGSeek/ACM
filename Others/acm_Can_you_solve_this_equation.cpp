#include <stdio.h>
#include <iostream>

using namespace std;

double f(double x)
{
    return 8*x*x*x*x + 7*x*x*x + 2*x*x +3*x +6.0;

}

int main()
{
    double x1 = 0, x2 = 100;
    double y;
    double mid;
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        x1 = 0;
        x2 = 100;
        scanf("%lf", &y);
        double y1 = f(x1) - y;
        double y2 = f(x2) - y;
        if(y1 > 0 || y2 < 0)
            printf("No solution!\n");
        else
        {
            while(f(x2)- f(x1) > 0.00001)
            {
                mid = (x1 + x2) / 2.0;
                if(y < f(mid))
                    x2 = mid;
                else if(y > f(mid))
                    x1 = mid;
                else
                    break;
            }
            printf("%.4f\n", mid);

        }
    }
    return 0;
}


