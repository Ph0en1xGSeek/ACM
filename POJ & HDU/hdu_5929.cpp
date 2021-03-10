#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int zero[400010];

int main()
{
    int ca, num;
    char str[10];
    int tmp;
    int ltop, rtop, lzero, rzero;
    bool flag;
    scanf("%d", &ca);
    for(int c = 1; c <= ca; c++)
    {
        printf("Case #%d:\n", c);
        memset(zero, 0, sizeof(zero));
        flag = true;
        ltop = lzero = 200005;
        rtop = rzero = 200006;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%s", str);
            if(str[2] == 'S')///push
            {
                scanf("%d", &tmp);
                if(flag)
                {
                    rtop++;
                    if(tmp == 0)
                        zero[rzero++] = rtop-1;
                }
                else
                {
                    ltop--;
                    if(tmp == 0)
                        zero[lzero--] = ltop+1;
                }
            }
            else if(str[2] == 'P')///pop
            {
                if(rtop > ltop+1)
                {
                    if(flag)
                    {
                        rtop--;
                        if(rzero > lzero+1 && rtop == zero[rzero-1])
                            rzero--;
                    }
                    else
                    {
                        ltop++;
                        if(rzero > lzero+1 && ltop == zero[lzero+1])
                            lzero++;
                    }
                }
            }
            else if(str[2] == 'E')///query
            {
                if(rtop <= ltop+1)
                    printf("Invalid.\n");
                else
                {
                    int ans;
                    if(rzero > lzero+1)
                    {
                        if(!flag)
                        {
                            if((rtop - zero[rzero-1] - 1) % 2 == 1)
                                ans = 0;
                            else
                                ans = 1;
                            if(zero[rzero-1] == ltop+1)
                                ans = 1-ans;

                        }
                        else
                        {
                            if((zero[lzero+1] - ltop - 1) % 2 == 1)
                                ans = 0;
                            else
                                ans = 1;
                            if(zero[lzero+1] == rtop-1)
                                ans = 1-ans;
                        }
                    }
                    else
                    {
                        if((rtop - ltop - 1) % 2 == 1)
                            ans = 1;
                        else
                            ans = 0;
                    }
                    printf("%d\n", ans);
                }
            }
            else///reverse
            {
                if(flag) flag = false;
                else flag = true;
            }
        }
    }
    return 0;
}
