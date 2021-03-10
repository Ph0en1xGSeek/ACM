#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 1e5

using namespace std;

int main()
{
    int a, b;
    int ans;
    while(~scanf("%d%d", &a, &b))
    {
        for(int i = 0; i < M; i++)
        {
            if(i*i > a)
            {
                ans = 1;
                break;
            }
            if(i*i + i > b)
            {
                ans = 2;
                break;
            }
        }
        if(ans == 1)
            printf("Vladik\n");
        else
            printf("Valera\n");
    }
    return 0;
}
