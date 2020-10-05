#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    while(~scanf("%s", str))
    {
        int len = strlen(str);
        int a = (len + 2) / 3;
        int b = (len + 2 ) % 3;
        for(int i = 0; i < a-1; i++)
        {
            printf("%c", str[i]);
            for(int j = 0; j < a+b-2; j++)
                printf(" ");
            printf("%c\n", str[len-1-i]);
        }
        for(int i = 0; i < a+b; i++)
        {
            printf("%c", str[a-1+i]);
        }
        printf("\n");
    }
    return 0;
}
