#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char str[15];
    int num, len, cnt = 0;
    while(scanf("%s", str) != EOF)
    {
        scanf("%d", &num);
        len = strlen(str);
        if(num > len)
        {
            num -= len;
            for(int i = 0; i < len; i++)
                if(str[i] == '0')
                {
                    cnt++;
                    for(int j = i; j < len; j++)
                        str[j] = str[j+1];
                    len--;
                    i--;
                }
            num %= len;
            for(int i = len - num; i < len; i++)
                printf("%c", str[i]);
            for(int i = 0; i < len - num; i++)
                printf("%c", str[i]);
            printf("\n");
        }
        else
        {
            for(int i = len - num; i < len; i++)
                if(str[i] != '0')
                    printf("%c", str[i]);
            for(int i = 0; i < len - num; i++)
                if(str[i] != '0')
                    printf("%c", str[i]);
            printf("\n");
        }
    }
    return 0;
}
