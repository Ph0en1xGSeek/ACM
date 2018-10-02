/*Only C++ compiler can Accepted*/
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double n, p;
    while(~scanf("%lf%lf", &n, &p)){
        printf("%.0lf\n", pow(p, 1/n));
    }
    return 0;
}
