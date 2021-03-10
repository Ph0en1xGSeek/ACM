#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    char str[100100];
    int ca, num;
    int left, right;
    bool flag ;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = true;
        scanf("%d", &num);
        scanf("%s", str);
        left = right = -1;
        for(int i = 0; i < num; i++)
            if(str[i] == ')')
            {
                left = i;
                break;
            }
        for(int i = num-1; i >= 0; i--)
            if(str[i] == '(')
            {
                right = i;
                break;
            }
        if(left == -1 || right == -1)
        {
            printf("No\n");
            continue;
        }
        swap(str[left], str[right]);
        left = right = 0;
        for(int i = 0; i < num; i++)
        {
            if(str[i] == '(')
                left++;
            else
            {
                if(left)
                    left--;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(left != 0) flag = 0;
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
