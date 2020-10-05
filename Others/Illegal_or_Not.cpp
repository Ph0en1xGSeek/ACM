#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool arr[1900];

int main()
{
    int num, a, d;
    int dp;
    bool flag;
    while(~scanf("%d", &num))
    {
        dp = 0;
        flag = true;
        memset(arr, false, sizeof(arr));
        for(int i = 0; i < num; i++)
        {
            scanf("%d%d", &a, &d);
            for(int j = a; j <= d; j++)
                arr[j] = true;
        }
        for(int i = 1; i <= 180; i++)
            if(arr[i])
                dp++;
        for(int i = 180; i <= 1826; i++)
        {
            if(dp > 90)
            {
                flag = false;
                break;
            }
            if(arr[i+1] == true && arr[i-179] == false)
                dp++;
            else if(arr[i+1] == false && arr[i-179] == true)
                dp--;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
