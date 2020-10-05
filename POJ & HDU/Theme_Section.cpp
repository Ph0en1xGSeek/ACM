#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[1000010];
int nex[1000010];
bool flag[1000010];
int len;

void kmp()
{
    int i = 0, j = -1;
    nex[0] = -1;
    while(i < len)
    {
        while(j != -1 && str[i] != str[j])
            j = nex[j];
        i++;
        j++;
        nex[i] = j;
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%s", str);
        len = strlen(str);
        kmp();
        int tmp = len;
        memset(flag, false, sizeof(flag));
        while(tmp > 0)
        {
            if(len >= 2*tmp)
                flag[tmp] = true;
            tmp = nex[tmp];
        }
        int ans = 0;
        for(int i = len-1; i > 1; i--)///枚举中间末尾位置
        {
            if(str[i-1] != str[len-1])
                continue;
            tmp = i;
            while(tmp > 0)
            {
                if(flag[tmp] && i >= 2*tmp && i+tmp <= len)///找到第一个的与之对应
                {
                    ans = max(ans, tmp);
                    break;
                }
                tmp = nex[tmp];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
