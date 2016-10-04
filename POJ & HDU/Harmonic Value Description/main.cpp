#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int ca, n, k, cc=1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &k);
        printf("Case #%d:", cc++);
        printf(" %d %d", k+k, k);
        for(int i = k-1; i >= 1; i--)
            printf(" %d", i);
        for(int i = k+1; i <= n; i++)
        {
            if(i == k+k) continue;
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
