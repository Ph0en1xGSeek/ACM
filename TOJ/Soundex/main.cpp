#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string lst = "01230120022455012623010202";
    char str[25];
    char pre, now;
    while(scanf("%s", str) != EOF)
    {
        pre = '#', now;
        for(int i = 0; str[i]; i++)
        {
            now = lst[str[i]-'A'];
            if(now != pre && now != '0')
                printf("%c", now);
            pre = now;
        }
        printf("\n");
    }
    return 0;
}
