#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int arr1[202], arr2[202];
int ca, n, m;
int bsearch(int x)
{
    int low = 1, high = m;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr2[mid] > x)
            high = mid - 1;
        else if(arr2[mid] < x)
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

int main()
{
    int counts, mid, tmp;
    scanf("%d", &ca);
    while(ca--)
    {
        counts = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr1[i]);
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
            scanf("%d", &arr2[i]);
        sort(arr2 + 1, arr2 + m + 1);
        for(int i = 1; i <= n; i++)
            if(mid = bsearch(-arr1[i]))
            {
                counts++;
                tmp = mid - 1;
                while(arr2[tmp] == arr2[mid] && tmp > 0)
                {
                    tmp--;
                    counts++;
                }
                tmp = mid + 1;
                while(arr2[tmp] == arr2[mid] && tmp <= m)
                {
                    tmp++;
                    counts++;
                }
            }
        printf("%d\n", counts);
    }
    return 0;
}
