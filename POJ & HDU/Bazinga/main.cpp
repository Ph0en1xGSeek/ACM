#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

char str[505][2016];
bool vis[505];
int ans, cc = 1;

int main()
{
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
            scanf("%s", str[i]);
        memset(vis, false, sizeof(vis));
        ans = -1;
        for(int i = 2; i <= num; i++)
            for(int j = i-1; j >= 1; j--)
            {
                if(vis[j]) continue;
                if(strstr(str[i], str[j]) == NULL)
                    ans = i;
                else
                    vis[j] = true;
            }
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
