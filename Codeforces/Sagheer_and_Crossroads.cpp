#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    bool flag = true;

    for(int i = 0; i < 4 && flag; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(arr[i][j])
            {
                if(arr[i][3])
                {
                    flag = false;
                    break;
                }
                if(arr[(i+3-j)%4][3])
                {
                    flag = false;
                    break;
                }
            }
        }
    }

    if(flag) printf("NO\n");
    else  printf("YES\n");
    return 0;
}
