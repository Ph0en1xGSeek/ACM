#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int num[30];
int cnt;

int main()
{
    int k;
    while(~scanf("%d", &k))
    {
        cnt = 0;
        if(k == 0)
        {
            printf("a\n");
            continue;
        }
        while(k > 0)
        {
            int i;
            for(i = 1; (i+1)*i/2 <= k; i++);
            num[cnt++] = i;
            k -= ((i)*(i-1)/2);
        }
        for(int i = 0; i < cnt; i++)
        {
            for(int j = 0; j < num[i]; j++)
                printf("%c", 'a' + i);
        }
        printf("\n");
    }
    return 0;
}
