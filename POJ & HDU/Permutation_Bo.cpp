#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    double c[1010];
    int num;
    double ans;
    while(scanf("%d" ,&num) != EOF)
    {
        ans = 0;
        for(int i = 0; i < num; i++)
            scanf("%lf", &c[i]);
        if(num == 1)
            ans = c[0];
        else
        {
            ans += (c[0] + c[num-1]) / 2;
            for(int i = 1; i < num -1; i++)
                ans += c[i]/3;
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}
