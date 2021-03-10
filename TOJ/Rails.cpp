#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1005

using namespace std;

int main()
{
    int num, i, j, top, flag;
    int b[N], s[N];
    while(scanf("%d", &num) != EOF && num)
    {
        while(scanf("%d", &b[0]) && b[0])
        {
            for(i = 1; i < num; i++)
                scanf("%d", &b[i]);
            j = 1;
            flag = 1;
            top = 0;
            for(i = 0; i < num; i++)
            {
                if(top > 0 && s[top-1] == b[i])
                    top--;
                else
                {
                    while(j <= num && j != b[i])
                    {
                        s[top] = j;
                        top++;
                        j++;
                    }
                    if(j <= num)   j++;
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag)    printf("Yes\n");
            else    printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
