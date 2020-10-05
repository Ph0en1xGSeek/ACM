#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int t, n, k, tmp = 0, pretmp;
    int mi = 0;
    while(~scanf("%d", &t))
    {
        for(int i = 0; i < t; i++)
        {
            scanf("%d%d", &n, &k);
            for(int j = 0; j < k; j++)
            {
                pretmp = tmp;
                scanf("%d", &tmp);
                if(j == 0)
                    mi = tmp;
                if(j > 0 && j < k-1)
                    mi = max(mi, (tmp-pretmp+2)/2);
                if(j == k-1)
                {
                    mi = max(mi, (tmp-pretmp+2)/2);
                    mi = max(mi, n-tmp+1);
                }

            }
            printf("%d\n", mi);
        }
    }
    return 0;
}
