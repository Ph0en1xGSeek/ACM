#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

char str[100010];
char st[100010];
int top;


int main()
{
    int ca;
    int num, tmpnum;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%s", str);
        scanf("%d", &num);
        tmpnum = num;
        int len = strlen(str);
        top = 0;
        st[top++] = str[0];
        for(int i = 1; i < len; i++)
        {
            while(num > 0 && top > 0 && st[top-1] > str[i])
            {
                top--;
                num--;
            }
            st[top++] = str[i];
        }
        while(num > 0)
        {
            top--;
            num--;
        }
        st[top] = '\0';
        printf("%s\n", st);

        top = 0;
        num = tmpnum;
        st[top++] = str[0];
        for(int i = 1; i < len; i++)
        {
            while(num > 0 && top > 0 && st[top-1] < str[i])
            {
                top--;
                num--;
            }
            st[top++] = str[i];
        }
        while(num > 0)
        {
            top--;
            num--;
        }
        st[top] = '\0';
        printf("%s\n", st);
    }
    return 0;
}
