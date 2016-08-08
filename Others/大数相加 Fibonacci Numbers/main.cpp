#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int a[1001], b[1001], c[1001];

    int num;
    while(scanf("%d", &num) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        if(num == 1 || num == 2)
            printf("1\n");
        else
        {
            a[1000] = b[1000] = 1;
            for(int i = 3; i <= num; i++)
            {
                for(int j = 1000; j > 0; j--)
                {
                    c[j] += a[j] + b[j];
                    c[j-1] += c[j] / 10;
                    c[j] %= 10;
                }
                memcpy(a, b, sizeof(a));
                memcpy(b, c, sizeof(b));
                memset(c, 0, sizeof(c));
            }
            int tmp;
            for(tmp = 0; b[tmp] == 0; tmp++);
            for(; tmp <= 1000; tmp++)
                printf("%d", b[tmp]);
            printf("\n");
        }

    }
    return 0;
}
