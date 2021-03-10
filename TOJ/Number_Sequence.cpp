#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num, len;
    while(scanf("%d", &num) && num)
    {
        len = 1;
        while(num != 1)
        {
            len++;
            if(num&1)   num = 3 * num + 1;
            else num >>= 1;
        }
        printf("%d\n", len);
    }
    return 0;
}
