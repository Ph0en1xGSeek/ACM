#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[1001];

bool bsearch(int x, int low, int high)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] > x)
            high = mid - 1;
        else if(arr[mid] < x)
            low = mid + 1;
        else
            return true;
    }
    return false;
}

int main()
{
    int num, p;
    while(scanf("%d", &num), num)
    {
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + num);
        for(p = num - 1; p > 1; p--)
        for(int i = 0; arr[i] <= arr[p]/2; i++)
            if(bsearch(arr[p]-arr[i], i+1, p))
            {
                printf("%d\n", arr[p]);
                goto end;
            }
        printf("-1\n");
        end:;
    }
    return 0;
}
