#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[1500];


int num;
bool flag;
long long divy1, divx1, x1, x2;
long long divy2, divx2, y1, y2;
bool flag2, flag3;

bool check(int x)
{
    for(int i = x; i < num; i++)
    {
        if(divy1 * (long long)(i - x1) == divx1 * (long long)(arr[i] - y1))
        {
            continue;
        }
        if(!flag2)
        {
            flag2 = true;
            divy2 = arr[i] - y2;
            divx2 = i-x2;
            if((long long)divx1*divy2 != (long long)divx2*divy1)
            {
                return false;
            }
            continue;
        }
        else
        {
            if((long long)divy2 * (i - x2) == (long long)divx2 * (arr[i] - y2))
            {
                continue;
            }
        }
        return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d", &num))
    {
        flag = true;
        flag2 = false;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }

        if(num == 3 && (arr[2]-arr[1] == arr[1]-arr[0]))
        {
            printf("No\n");
            continue;
        }
        else if(num == 3)
        {
            printf("Yes\n");
            continue;
        }

        if(arr[2] - arr[1] == arr[1] - arr[0])
        {
            flag2 = false;
            divy1 = arr[1] - arr[0];
            divx1 = 1;
            y1 = arr[0];
            x1 = 0;
            int i;
            for(i = 3; i < num; i++)
                if(arr[i] - arr[i-1] != arr[1] - arr[0])
                    break;
            if(i >= num)
                flag = false;
            else
            {
                y2 = arr[i];
                x2 = i;
                flag = check(i+1);
            }
        }
        else
        {
            if(1)///0.1
            {
                flag2 = false;
                divy1 = arr[1] - arr[0];
                divx1 = 1;
                y1 = arr[0];
                x1 = 0;
                y2 = arr[2];
                x2 = 2;
                flag = check(3);
            }
     ///====================================================
            if(!flag)///0.2
            {
                flag2 = false;
                divy1 = arr[2] - arr[0];
                divx1 = 2;
                y1 = arr[0];
                x1 = 0;
                y2 = arr[1];
                x2 = 1;
                flag = check(3);
            }
     ///====================================================
            if(!flag)///1.2
            {
                flag2 = false;
                divy1 = arr[2] - arr[1];
                divx1 = 1;
                y1 = arr[1];
                x1 = 1;
                y2 = arr[0];
                x2 = 0;
                flag = check(3);
            }

        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
