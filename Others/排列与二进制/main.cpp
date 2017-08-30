#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int m, n;
    int cnt;
    while(scanf("%d%d", &n, &m) && n != 0)
    {
        cnt = 0;
        for(int i = n; i > n-m; i--)
        {
            if(i%2 == 1) continue;
            int tmp = i;
            while((tmp&1) == 0)
            {
                tmp >>= 1;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
