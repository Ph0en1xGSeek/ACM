#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int tmp;
    int num;
    bool cnt;
    while(~scanf("%d", &num))
    {
        cnt = false;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &tmp);
            if(tmp & 1)
                cnt = 1;
        }

        if(cnt == 1)
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
