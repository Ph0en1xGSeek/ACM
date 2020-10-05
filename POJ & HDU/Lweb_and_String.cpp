#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    bool vis[30];
    char str[100010];
    int ca, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(!vis[str[i] - 'a'])
            {
                ans ++;
                vis[str[i] - 'a'] = 1;
            }
        }
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
