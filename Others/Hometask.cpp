#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[100010], s[3];

int main()
{
    int n, i, j, ans;
    int lcnt, rcnt;
    while(~scanf("%s",str))
    {
        scanf("%d", &n);
        for(ans = i = 0; i < n; i++)///每个这个pair组成的分区内较少的那个字母数量
        {
            scanf("%s",s);///因为只要独立分区内只要有不同的字母就必定有不好的pair
            for(j = 0; str[j]; j++)
            {
                lcnt = rcnt = 0;
                while(str[j] == s[0] || str[j] == s[1])
                {
                    if(str[j] == s[0])
                        lcnt++;
                    else
                        rcnt++;
                    j++;
                }
                ans += min(lcnt, rcnt);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
