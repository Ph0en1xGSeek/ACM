#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int cnt;

int main()
{
    int num;
    int tmp1, tmp2;
    while(~scanf("%d", &num))
    {
        scanf("%d", &tmp1);
        for(int i = 0; i < num-2; i++)
            scanf("%d", &cnt);
        if(num > 1)
            scanf("%d", &tmp2);
        if(num == 1)
        {
            if(tmp1%2 ==1)
                printf("Yes\n");
            else
                printf("No\n");
            return 0;
        }
        if(((tmp1&1) && (tmp2 & 1)) && (num&1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
