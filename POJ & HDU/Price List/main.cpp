#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int ca;
    int n, m;
    long long tmp;
    long long tot;
    scanf("%d", &ca);
    while(ca--)
    {
        tot = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            tot += tmp;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%lld", &tmp);
            if(tmp > tot)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
