#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int tmp, ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        int ans = 0;
        while(num--)
        {
            scanf("%d", &tmp);
            if(tmp % 4 == 3)
                ans ^= tmp+1;
            else if(tmp % 4 == 0)
                ans ^= tmp -1;
            else
                ans ^= tmp;
        }
        if(ans != 0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
