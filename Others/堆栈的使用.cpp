#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int st[10005];
char op[10];

int main()
{
    int num;
    int tmp;
    int top = 0;
    while(~scanf("%d", &num) && num != 0)
    {
        top = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%s", op);
            if(op[0] == 'P')
            {
                scanf("%d", &tmp);
                st[top++] = tmp;
            }
            else if(op[0] == 'O')
            {
                if(top > 0)
                    top--;
            }
            else if(op[0] == 'A')
            {
                if(top == 0)
                    printf("E\n");
                else
                {
                    printf("%d\n", st[top-1]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
