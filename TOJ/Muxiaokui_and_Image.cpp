#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char str[105];
    int ca, num, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &num);
        while(num--)
        {
            scanf("%s", str);
            if(strlen(str) >= 2 && str[0] == '\\' && str[1] != '\\')
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
