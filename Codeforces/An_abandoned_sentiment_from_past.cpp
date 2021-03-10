#include <iostream>
#include <stdio.h>
#include <algorithm>>
#include <string.h>
#define INF 100000


using namespace std;

int arr[105], brr[105];

int main()
{
    int n, k;
    int mi, mx;
    int pos;
    bool flag = true;
    while(~scanf("%d%d", &n, &k))
    {
        flag = false;
        mi = INF;
        mx = -INF;
        arr[0] = -INF;
        arr[n+1] = INF;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i] == 0)
                pos = i;
        }
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &brr[i]);
            mx = max(mx, brr[i]);
            mi = min(mi, brr[i]);
        }
        if(k > 1)
            flag = true;
        else
        {
            arr[pos] = brr[0];
            for(int i = 2; i <= n; i++)
            {
                if(arr[i-1] > arr[i])
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
