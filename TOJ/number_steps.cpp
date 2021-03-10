#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int ca, x, y;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &x, &y);
        if(x != y + 2 && x != y)
            printf("No Number\n");
        else
            if(x&1)
                printf("%d\n", x+y-1);
            else
                printf("%d\n", x+y);
    }

    return 0;
}
