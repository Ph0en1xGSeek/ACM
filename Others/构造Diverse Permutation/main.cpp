
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool vis[100008];

int main(void)
{
    int n,k;
    while(scanf("%d%d",&n,&k) !=EOF)
    {
        memset(vis, 0, sizeof(vis));
        printf("1");
        int x = 1;
        int t = 1;
        for(int i = k; i > 0; i--)
        {
            if(t == 1)
            {
                printf(" %d",x + i);
                x += i;
            }
            else
            {
                printf(" %d",x - i);
                x -= i;
            }
            t ^= 1;
        }
        for(int i = k+2; i <= n; i++)///和前一项差值一定也在k之内
            printf(" %d", i);
        printf("\n");
    }
    return 0;
}

