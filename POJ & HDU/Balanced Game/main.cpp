#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        if(num&1)
            printf("Balanced\n");
        else
            printf("Bad\n");
    }
    return 0;
}
