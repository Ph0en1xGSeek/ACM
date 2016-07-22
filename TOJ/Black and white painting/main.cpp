#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c;
    int ans;
    while(~scanf("%d%d%d", &a, &b, &c), a)
    {
        if(c == 1)
        {
            if(a == 8 || b == 8)
                ans = (1+(a-8)/2)*(1+(b-8)/2);
            else
                ans = (1+(a-8)/2)*(1+(b-8)/2) + (1+(a-9)/2)*(1+(b-9)/2);
        }
        else
        {
            if(a == 8 && b == 8)
                ans = 0;
            else if(a == 8)
                ans = (1+(b-9)/2);
            else if(b == 8)
                ans = (1+(a-9)/2);
            else
                ans = (1+(a-8)/2)*(1+(b-9)/2) + (1+(a-9)/2)*(1+(b-8)/2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
