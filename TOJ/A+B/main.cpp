#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int flag[1010];
    int tmp, ca, num;
    scanf("%d", &ca);
    long long ans = 0;
    while(ca--)
    {
        memset(flag, 0, sizeof(flag));
        scanf("%d", &num);
        while(num--)
        {
            scanf("%d", &tmp);
            flag[tmp]++;
        }
        scanf("%d", &num);
        while(num--)
        {
            ans = 0;
            scanf("%d", &tmp);
            for(int i = 0; i <= 1000; i++)
            {
                if(tmp - i > 1000 || tmp - i < 0)
                    continue;
                if(tmp - i == i)
                    ans += (long long)(flag[i] * (flag[i]-1));
                else
                    ans += (long long)(flag[i] * flag[tmp-i]);
            }
            printf("%lld\n", ans);
        }

    }
    return 0;
}
