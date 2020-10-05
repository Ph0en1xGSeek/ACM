#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

double n[105];

int main()
{
    int k;
    double ang, index;
    while(~scanf("%d", &k))
    {
        for(int i = 0; i < k; i++)
            scanf("%lf", &n[i]);
        scanf("%lf", &ang);
        index = n[0];
        for(int i = 1; i < k; i++)
        {
            if(index / n[i] * sin(ang) > 1.0)
            {
                printf("NO\n");
                continue;
            }
        }
        index /= n[k-1];
        double ans = asin(index * sin(ang));
        cout << setprecision(3) << fixed << ans << endl;
    }
    return 0;
}
