#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char str[200010];
    int num;
    while(~scanf("%d", &num) && num != 0)
    {
        scanf("%s", str);
        if(num&1)
        {
            printf("-1\n");
            continue;
        }
        int cnt = 0, source;
        for(int i = 0; i < num; i++)
        {
            if(str[i] == 'H')
                cnt++;
            if(i == num/2-1)
                source = cnt;
        }
        if(cnt&1)
        {
            printf("-1\n");
            continue;
        }
        memcpy(str+num, str, sizeof(char)*num);
        int i;
        for(i = 0; i < num; i++)
        {
            if(source == (cnt >> 1)) break;
            if(str[i] == 'T' && str[i+num/2] == 'H')
                source++;
            else if(str[i] == 'H' && str[i+num/2] == 'T')
                source--;
        }
        int j = (i+num/2)%num;
        if(i == 0||j == 0)
            printf("1\n%d\n", num/2);
        else
            printf("2\n%d %d\n", min(i, j), max(i, j));
    }
    return 0;
}
