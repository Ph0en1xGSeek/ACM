#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[10010];

int main()
{
    int l, m;
    int a, b;
    int cnt = 0;
    while(~scanf("%d%d", &l, &m))
    {
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            memset(arr+a, 1, (b-a+1)<<2);
        }
        for(int i = 0; i <= l; i++)
            if(arr[i] == 0)
                cnt++;

        printf("%d\n", cnt);
    }
    return 0;
}
