#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    long long arr[100010];
    long long v[100010];
    int ca, n, m;
    int x;
    long long y;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%I64d", &v[i]);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%I64d", &x, &y);
            arr[x-1] += y;
        }
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] > v[i])
            {
                arr[i+1] += (arr[i]-v[i]);
                arr[i] = v[i];
            }
        }
        printf("%I64d\n", max(0ll, arr[n-1]-v[n-1]));
        if(arr[n-1] > v[n-1]) arr[n-1] = v[n-1];
        printf("%I64d", arr[0]);
        for(int i = 1; i < n; i++)
            printf(" %I64d", arr[i]);
        printf("\n");
    }
    return 0;
}
