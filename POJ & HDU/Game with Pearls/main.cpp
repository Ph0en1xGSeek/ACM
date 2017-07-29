#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    bool flag;
    int cnt[200];
    int ca, n, k, tmp;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = true;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(cnt[i] == 0)
            {
                flag = false;
                break;
            }
            while(cnt[i] > 1)
            {
                cnt[i]--;
                cnt[i+k]++;
            }
        }
        if(flag)
            puts("Jerry");
        else
            puts("Tom");
    }
    return 0;
}
