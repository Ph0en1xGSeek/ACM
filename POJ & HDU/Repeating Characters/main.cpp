#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char str1[25];
    char str2[200];
    int ca, n, m;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(str2, 0, sizeof(str2));
        scanf("%d%d", &n, &m);
        scanf("%s", str1);
        for(int i = 0; i < strlen(str1); i++)
        {
            for(int j = 0; j < m; j++)
                str2[i*m+j] = str1[i];
        }
        printf("%d %s\n", n, str2);
    }
    return 0;
}
