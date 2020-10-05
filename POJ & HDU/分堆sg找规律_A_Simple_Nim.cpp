#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, n, tmp;
    scanf("%d", &ca);
    while(ca--)
    {
        int ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(tmp % 8 == 7)
                tmp++;
            else if(tmp % 8 == 0)
                tmp--;
            ans ^= tmp;
        }
        if(ans)
            printf("First player wins.\n");
        else
            printf("Second player wins.\n");
    }
    return 0;
}
