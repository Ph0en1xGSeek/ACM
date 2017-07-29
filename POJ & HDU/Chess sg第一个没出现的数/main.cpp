#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int sg[1<<21];
int record[25];

void init()
{
    ///״̬ѹ����ö���������ӵ����
    for(int i = 1; i < (1<<20); i++)
    {
        int last = -1;///��ǰ1���Ƶ����Ǹ�0
        memset(record, -1, sizeof(record));
        for(int j = 0 ;j < 20; j++)
        {
            if(!((i>>j)&1))///��jλΪ0
            {
                last = j;
            }
            else if(last != -1)///��jλΪ1,���ұ���0
            {
                record[sg[i^(1<<j)^(1<<last)]] = 1;
                ///��jλ��0��last��1�������sg���Ϊ���ֹ�
            }
        }
        int j = 0;
        while(record[j] == 1)   j++;
        sg[i] = j;
    }
}

int main()
{
    int ca, col, row, bit;
    int tmp, ans;
    init();
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &row);
        for(int i = 0 ;i < row; i++)
        {
            tmp = 0;
            scanf("%d", &col);
            while(col--)
            {
                scanf("%d", &bit);
                tmp |= (1 << (20-bit));
            }
            ans ^= sg[tmp];
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
