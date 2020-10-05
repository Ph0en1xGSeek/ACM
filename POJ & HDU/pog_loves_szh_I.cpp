#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char str[104];
    char s1[104];
    char s2[104];
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        scanf("%s", str);
        for(int i = 0; str[i]; i++)
        {
            if(i&1)
                s2[i>>1] = str[i];
            else
                s1[i>>1] = str[i];
        }
        printf("%s\n", s1);
        for(int i = strlen(s2)-1; i >= 0; i--)
            printf("%c", s2[i]);
        printf("\n");
    }
    return 0;
}
