#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n, k;
    int today, tmp;
    bool flag;
    int ans = -1;
    while(~scanf("%d%d", &n, &k))
    {
        ans = -1;
        flag = false;
        tmp = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &today);
            if(!flag)
            {
                if(today > 8)
                {
                    tmp += (today - 8);
                    today = 8;
                }
                else
                {
                    if(tmp + today > 8)
                    {
                        tmp -= (8 - today);
                        today = 8;
                    }
                    else
                    {
                        today += tmp;
                        tmp = 0;
                    }
                }
                k -= today;
                if(k <= 0)
                {
                    flag = true;
                    ans = i;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
