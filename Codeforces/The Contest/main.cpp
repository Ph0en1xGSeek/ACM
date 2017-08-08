#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    int tmp;
    int l, r;
    int mx;
    int sum;
    bool flag;
    while(~scanf("%d", &num))
    {
        flag = true;
        sum = 0;
        mx = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &tmp);
            sum += tmp;
        }
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d%d", &l, &r);
            if(flag)
            {
                if(l >= sum)
                {
                    flag = false;
                    mx = l;
                }
                else if(r >= sum)
                {
                    flag = false;
                    mx = sum;
                }
            }
        }

        if(flag) printf("-1\n");
        else printf("%d\n", mx);
    }
    return 0;
}
