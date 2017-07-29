#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    bool flag;
    int arr[10];
    char s[11] = "pqruvwxyz";
    int ca;
    int i;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = false;
        for(i = 0; i < 10; i++)
            scanf("%d", &arr[i]);

        for(i = 0; i < 9; i++)
        {
            if(arr[i] == 1)
            {
                if(flag == false)
                    printf("%c", s[i]);
                else
                    printf("+%c", s[i]);
                flag = true;
            }
            else if(arr[i] == -1)
            {
                flag = true;
                printf("-%c", s[i]);
            }
            else if(arr[i] < 0)
            {
                flag = true;
                printf("%d%c", arr[i], s[i]);
            }
            else if(arr[i] > 0)
                if(flag)
                    printf("+%d%c", arr[i], s[i]);
                else
                {
                    flag = true;
                    printf("%d%c", arr[i], s[i]);
                }
        }
        if(arr[9] > 0)
            if(flag)
                printf("+%d", arr[9]);
            else
            {
                flag = true;
                printf("%d", arr[9]);
            }
        else if(arr[9] < 0)
        {
            flag = true;
            printf("%d", arr[9]);
        }
        if(!flag) printf("0");
        printf("\n");
    }
    return 0;
}
