#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char str1[12], str2[12];
    int cnt, add, len1, len2;
    while(scanf("%s %s", str1, str2) !=EOF)
    {
        if(str1[0] == '0' && str2[0] == '0')    break;
        cnt = add = 0;
        len1 = strlen(str1);
        len2 = strlen(str2);
        len1--, len2--;
        while(len1 >= 0 && len2 >= 0)
        {
            if(str1[len1]-'0' + str2[len2]-'0' + add >= 10)
            {
                cnt++;
                add = 1;
            }
            else
                add = 0;
            len1--;
            len2--;
        }
        if(len1 >=0)
            while(str1[len1]-'0' + add >= 10 && len1 >=0)
            {
                 cnt++;
                 len1--;
            }
        if(len2 >=0)
            while(str2[len2]-'0' + add >= 10)
            {
                len2--;
                cnt++;
            }
        if(cnt == 0)    printf("No carry operation.\n");
        else if(cnt == 1)   printf("1 carry operation.\n");
        else    printf("%d carry operations.\n", cnt);
    }
    return 0;
}
