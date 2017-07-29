/**除了两辆相等后手赢之外，其他都是先手赢
先手总有办法制造出两两相等且能保持这个状态**/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int cnt[102];

int main()
{
    int num, tmp, flag;
    while(scanf("%d", &num) && num)
    {
        flag = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        for(int i = 1; i < 101; i++)
            if(cnt[i] & 1) flag = 1;
        printf("%d\n", flag);
    }
    return 0;
}
