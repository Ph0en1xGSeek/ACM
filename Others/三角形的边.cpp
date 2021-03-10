#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) && a > 0)
    {
        if(a > b)
            swap(a, b);
        if(a > c)
            swap(a, c);
        if(b > c)
            swap(b, c);
        printf("%d\n", a+b-c);
    }
    return 0;
}
