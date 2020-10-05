#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, num, tmp, cc = 1;
    int left, right;
    int ml, mr;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        int sum, mx;
        scanf("%d", &sum);
        mx = sum;
        left = right = 1;
        ml = mr = 1;
        for(int i = 2; i <= num; i++)
        {
            scanf("%d", &tmp);
            if(sum < 0)
                sum = tmp, left = i;
            else
                sum += tmp;
            if (sum > mx)
            {
                mx = sum;
                right = i;
                ml = left;
                mr = right;
            }
        }
        printf("Case %d:\n", cc++);
        printf("%d %d %d\n", mx, ml, mr);
        if(ca)
            printf("\n");
    }
    return 0;
}
