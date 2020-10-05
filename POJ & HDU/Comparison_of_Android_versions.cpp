#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str1[10], str2[10];

int cmp1()
{
    if(str1[0] < str2[0])
        return -1;
    else if(str1[0] == str2[0])
        return 0;
    else
        return 1;
}

int cmp2()
{
    for(int i = 2; i < 5; i++)
    {
        if(str1[i] > str2[i])
            return 1;
        else if(str1[i] < str2[i])
            return -1;
    }
    if(str1[1] != str2[1])
        return 0;
    else
        if(str1[5] == str2[5])
            return 0;
        else
        {
            if(str1[5] == '\0')
                return 1;
            if(str2[5] == '\0')
                return -1;
            if(str1[5] < str2[5])
                return -1;
            else
                return 1;
        }
}

int main()
{
    int ca, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%s%s", str1, str2);
        printf("Case %d:", cc++);
        if(cmp1() == -1)
            printf(" %c", '<');
        else if(cmp1() == 0)
            printf(" %c", '=');
        else
            printf(" %c", '>');
        if(cmp2() == -1)
            printf(" %c", '<');
        else if(cmp2() == 0)
            printf(" %c", '=');
        else
            printf(" %c", '>');
        printf("\n");
    }
    return 0;
}
