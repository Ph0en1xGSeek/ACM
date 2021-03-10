#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int num;
    bool flag = false;
    while(scanf("%d", &num) && num != 0)
    {
        flag = false;
        for(int i = 2; i * i <= num; i++)
        {
            if(num % (i*i) == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
