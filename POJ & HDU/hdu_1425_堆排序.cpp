#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[1000010];

int n, m;


///Heap Sort
void heapAdjust(int pos, int len)
{
    int tmp = arr[pos];
    for(int j = 2*pos+1; j < len; j = j*2+1)
    {
        if(j < len-1 && arr[j] < arr[j+1]) j++;
        if(tmp > arr[j])
            break;
        arr[pos] = arr[j];
        pos = j;
    }
    arr[pos] = tmp;
}

void makeHeap(int pos, int len)
{
    for(int i = (len-2)/2; i >= 0; i--)
    {
        heapAdjust(i, len);
    }
//    for(int i = 0; i < n; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
}

int heapPop(int len)
{
    swap(arr[0], arr[len-1]);
    heapAdjust(0, len-1);
    return arr[len-1];
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        makeHeap(0, n);
        for(int i = 0; i < m; i++)
            heapPop(n-i);
        printf("%d", arr[n-1]);
        for(int i = n-2; i >= n-m; i--)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}
