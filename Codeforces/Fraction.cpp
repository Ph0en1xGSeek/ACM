#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        if(num % 2 == 0)
        {
            for(int i = num/2-1; i >= 1; i--)
            {
                if(__gcd(i, num-i) == 1)
                {
                    printf("%d %d\n", i, num-i);
                    break;
                }
            }
        }
        else
        {
            for(int i = num/2; i >= 1; i--)
            {
                if(__gcd(i, num-i) == 1)
                {
                    printf("%d %d\n", i, num-i);
                    break;
                }
            }
        }
    }
    return 0;
}
