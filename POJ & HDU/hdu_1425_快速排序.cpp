#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[1000010];

int n, m;

///Quick Sort
void quickSort(int low, int high)
{
    if(low >= high)
        return;
    int tmp = arr[low];
    int l = low, h = high;
    while(l < h)
    {
        while(l < h && arr[h] >= tmp)
            h--;
        arr[l] = arr[h];
        while(l < h && tmp >= arr[l])
            l++;
        arr[h] = arr[l];
    }
    arr[l] = tmp;
    quickSort(low, l-1);
    quickSort(l+1, high);
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        quickSort(0, n-1);
        printf("%d", arr[n-1]);
        for(int i = n-2; i >= n-m; i--)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
