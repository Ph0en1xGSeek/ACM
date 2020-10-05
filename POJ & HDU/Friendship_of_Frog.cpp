#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char str[1080];
    int before[28];
    int ca, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        int ans = 666666;
        memset(before, -1, sizeof(before));
        int a = -1, b = -1, c = -1;
        scanf("%s", str);
        printf("Case #%d: ", cc++);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            int tmp = str[i] - 'a';
            if(before[tmp] == -1)
                before[tmp] = i;
            else
            {
                ans = min(ans, i - before[tmp]);
                before[tmp] = i;
            }
        }
        if(ans == 666666) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
