#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int ca, c = 1;
    double ans;
    int m , n;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &m, &n);
        if((m&1) == 0 || (n&1) == 0)
            ans = m * n;
        else
            ans = m * n + 0.41;
        printf("Scenario #%d:\n", c++);
        printf("%.2f\n\n", ans);
    }
    return 0;
}
