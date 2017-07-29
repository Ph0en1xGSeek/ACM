#include <stdio.h>

using namespace std;

int main()
{
    printf("2992\n2993\n2994\n2995\n2996\n2997\n2998\n2999\n");
    int sum1, sum2, sum3, remain, d;
    for(int i = 3000; i < 10000; i++)
    {
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        d = i;
        while(d)
        {
            remain = d % 16;
            sum1 += remain;
            d = d / 16;
        }
        d = i;
        while(d)
        {
            remain = d % 12;
            sum2 += remain;
            d = d / 12;
        }
        if(sum1 == sum2)
        {
            d = i;
            while(d)
            {
                remain = d % 10;
                sum3 += remain;
                d = d / 10;
            }
            if(sum2 == sum3)
                printf("%d\n", i);
        }
    }
    return 0;
}
