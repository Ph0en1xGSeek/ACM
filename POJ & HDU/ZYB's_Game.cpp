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
        if((num & 1) == 0)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
