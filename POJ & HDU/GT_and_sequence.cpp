#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, num;
    scanf("%d", &ca);
    long long tmp, ans;
    long long negative[65];
    int p;
    int flag;
    while(ca--)
    {
        flag = 0;
        scanf("%d", &num);
        if(num == 1)
        {
            scanf("%I64d", &tmp);
            printf("%I64d\n", tmp);
            continue;
        }
        p = 0;
        ans = 1;
        for(int i = 0; i < num; i++)
        {
            scanf("%I64d", &tmp);
            if(tmp > 0)
            {
                ans *= tmp;
            }
            else if(tmp < 0)
                negative[p++] = -tmp;
            else
                flag++;
        }
        if(flag + p == num && p <= 1)
        {
            printf("0\n");
            continue;
        }
        sort(negative, negative+p);
        if(p%2 == 0)
            for(int i = 0; i < p; i++)
                ans *= negative[i];
        else
            for(int i = 1; i < p; i++)
                ans *= negative[i];
        printf("%I64d\n", ans);
    }
    return 0;
}
