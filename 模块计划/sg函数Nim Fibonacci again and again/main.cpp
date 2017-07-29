#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int f[100] = {1, 2};
int sg[1001] = {0, 1, 2, 3, 0, 1};
int flag[16];

int main()
{
    for(int i = 2; f[i-1] <= 1000; i++)
        f[i] = f[i-1] + f[i-2];
    for(int i = 6; i < 1001; i++)
    {
        sg[i] = i;
        memset(flag, 0, sizeof(flag));
        for(int j = 0; f[j] <= i; j++)
            flag[sg[i-f[j]]] = 1;
        for(int j = 0; j < 16; j++)
            if(flag[j] == 0)
            {
                sg[i] = j;
                break;
            }
    }
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) && (a|b|c))
    {
        if((sg[a]^sg[b]^sg[c]) == 0)
            printf("Nacci\n");
        else
            printf("Fibo\n");
    }
    return 0;
}
