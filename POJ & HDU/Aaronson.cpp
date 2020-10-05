#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[50];
    int ca, n, m;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(arr, 0, sizeof(arr));
        int cnt = 0, sum = 0;
        scanf("%d%d", &n, &m);
        while(n)
        {
            arr[cnt++] = n&1;
            n >>= 1;
        }
        if(cnt > m)
            for(int i = cnt-1; i >= m; i--)
                if(arr[i])
                    sum += 1<<(i-m);
        for(int i = min(m-1, 49); i >= 0; i--)
            if(arr[i])
                sum++;
        printf("%d\n", sum);
    }
    return 0;
}
