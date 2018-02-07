#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, pos, l, r;
    while(~scanf("%d%d%d%d", &n, &pos, &l, &r))
    {
        if(l == 1 && r == n)
        {
            printf("0\n");
        }
        else if(l == 1)
        {
            if(pos > r)
            {
                printf("%d\n", pos-r+1);
            }
            else
            {
                printf("%d\n", r-pos+1);
            }
        }
        else if(r == n)
        {
            if(pos < l)
            {
                printf("%d\n", l-pos+1);
            }
            else
            {
                printf("%d\n", pos-l+1);
            }
        }
        else
        {
            if(pos > r)
            {
                printf("%d\n", pos-l+2);
            }
            else if(pos < l)
            {
                printf("%d\n", r-pos+2);
            }
            else
            {
                printf("%d\n", (r-l) + 2 + min(r-pos, pos-l));
            }
        }
    }
    return 0;
}
