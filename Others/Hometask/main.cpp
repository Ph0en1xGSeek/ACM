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
        for(ans = i = 0; i < n; i++)///ÿ�����pair��ɵķ����ڽ��ٵ��Ǹ���ĸ����
        {
            scanf("%s",s);///��ΪֻҪ����������ֻҪ�в�ͬ����ĸ�ͱض��в��õ�pair
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
