#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int ca, c, num;
    int b, d;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &c ,&num);
        int a = (num*(num+1))>>1;
        int b = (num*((2*num-1)+1))>>1;
        int d = (num*(2*num+2))>>1;
        printf("%d %d %d %d\n", c, a, b, d);
    }
    return 0;
}

