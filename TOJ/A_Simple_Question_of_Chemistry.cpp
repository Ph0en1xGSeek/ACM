#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double now, pre, ans;
    scanf("%lf", &pre);
    while(scanf("%lf", &now) && now != 999.0)
    {
        ans = now - pre;
        pre = now;
        printf("%.2f\n", ans);
    }
    printf("End of Output\n");
    return 0;
}
