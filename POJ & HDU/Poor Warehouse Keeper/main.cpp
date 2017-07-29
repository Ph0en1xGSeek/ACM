#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#define esp 1e-6

using namespace std;

int main()
{
    double x, y;
    while(~scanf("%lf %lf", &x, &y))
    {
        if(x > y)
        {
            printf("-1\n");
            continue;
        }
        double radio = (y+1-esp)/x;
        int ans = (int)x - 1;
        double tmp = 1;///模拟现在总价
        for(int i = 1; i <= (int)x; i++)///模拟每次增加个数
        {
            int t = (int)(i*radio - tmp);
            tmp += t;
            ans += t;
            tmp = tmp*(i+1)/i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
