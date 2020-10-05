#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int ca, num;
    int a, b, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &num);
        for(int i = num - 46; i < num; i++)
        {
            if(i < 0)
                continue;
            a = b = i;
            while(b)
            {
                a += b % 10;
                b /= 10;
            }
            if(a == num)
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
