#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int ca;
    int num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        int a = floor(sqrt(num));
        int b;
        for(; a > 0; a--)
            if(num % a == 0)
            {
                b = num / a;
                break;
            }
        int ans = (a + b) << 1;
        printf("%d\n", ans);
    }
    return 0;
}
