#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int n, k;
    int tmp;
    int mi;
    while(~scanf("%d%d", &n, &k))
    {
        mi = 1000;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(k % tmp == 0)
            {
                mi = min(k / tmp, mi);
            }
        }
        printf("%d\n", mi);
    }
    return 0;
}
