#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int cnt = 0;
    char str[100];
    while(~scanf("%s", str))
    {
        if(strcmp(str, "<br>") == 0)
        {
            cnt = 0;
            printf("\n");
        }
        else if(strcmp(str, "<hr>") == 0)
        {
            if(cnt == 0)
                printf("--------------------------------------------------------------------------------\n");
            else
                printf("\n--------------------------------------------------------------------------------\n");
            cnt = 0;
        }
        else
        {
            int len = strlen(str);
            if(cnt == 0)
            {
                cnt = len;
                printf("%s", str);
            }
            else if(cnt + len + 1 > 80)
            {
                cnt = len;
                printf("\n");
                printf("%s", str);
            }
            else
            {
                cnt += len+1;
                printf(" %s", str);
            }
        }
    }
    printf("\n");
    return 0;
}
