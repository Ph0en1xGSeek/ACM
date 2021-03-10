#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    bool flag;
    char st[100100];
    int top;
    int cnt;
    int ca;
    scanf("%d", &ca);
    char str[100100];
    int num;
    while(ca--)
    {
        scanf("%s %d", str, &num);
        top = -1;
        cnt = 0;
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            while(top >= 0 && cnt < num && str[i] < st[top])
            {
                top--;
                cnt++;
            }
            st[++top] = str[i];
        }
        while(cnt < num)
        {
            top--;
            cnt++;
        }
        st[++top] = '\0';
        printf("%s\n", st);

        top = -1;
        cnt = 0;
        for(int i = 0; i < len; i++)
        {
            while(top >= 0 && cnt < num && str[i] > st[top])
            {
                top--;
                cnt++;
            }
            st[++top] = str[i];
        }
        while(cnt < num)
        {
            top--;
            cnt++;
        }
        st[++top] = '\0';
        printf("%s\n", st);
    }
    return 0;
}
