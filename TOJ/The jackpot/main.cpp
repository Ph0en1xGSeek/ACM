#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int sum, mx, tmp;
    while(scanf("%d", &num) && num != 0)
    {
        sum = mx = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &tmp);
            sum += tmp;
            if(sum < 0) sum = 0;
            else
                if(sum > mx)
                    mx = sum;
        }
        if(mx == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", mx);
    }
    return 0;
}
