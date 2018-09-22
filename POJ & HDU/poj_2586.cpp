#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int s, d;
    while(~scanf("%d%d", &s, &d))
    {
        if(s*4 < d)
        {
            if(10*s > 2*d)
            {
                printf("%d\n", 10*s - 2*d);
            }
            else
            {
                printf("Deficit\n");
            }
        }
        else if(s*3 < d*2)
        {
            if(8*s > 4*d)
            {
                printf("%d\n", 8*s - 4*d);
            }
            else
            {
                printf("Deficit\n");
            }
        }
        else if(s*2 < d*3)
        {
            if(6*s > 6*d)
            {
                printf("%d\n", 6*s - 6*d);
            }
            else
            {
                printf("Deficit\n");
            }
        }
        else if(s < d*4)
        {
            if(3*s > 9*d)
            {
                printf("%d\n", 3*s - 9*d);
            }
            else
            {
                printf("Deficit\n");
            }
        }
        else
        {
            printf("Deficit\n");
        }
    }
    return 0;
}
