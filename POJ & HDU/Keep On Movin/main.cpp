#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int ca, num, tmp, even;
    int n;
    scanf("%d", &ca);
    while(ca--)
    {
        tmp = 0, even = 0;
        scanf("%d", &num);
        while(num--)
        {
            scanf("%d", &n);
            if(n&1)
            {
                even += n-1;
                tmp++;
            }
            else
                even += n;
        }
        if(tmp == 0)
            printf("%d\n", even);
        else
            printf("%d\n", (even/2)/tmp*2+1);
    }
    return 0;
}
