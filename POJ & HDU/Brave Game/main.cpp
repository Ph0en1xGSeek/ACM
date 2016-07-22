#include <iostream>
#include <stdio.h>

using namespace std;

int sg[1001] = {0};

int main()
{
    int num, n, m;
    scanf("%d", &num);
    while(num--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            sg[i] = 0;
            for(int j = 1; j <= m && i-j >= 0; j++)
            {
                if(sg[i-j] == 0)
                    sg[i] = 1;
            }
        }
        if(sg[n] == 1)
            printf("first\n");
        else
            printf("second\n");
    }
    return 0;
}
