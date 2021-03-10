#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[100010];
int brr[100010];

void mergeList(int a[], int b[], int l, int mid, int r)
{
    int i = l, j = mid+1, k = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
}

void mergeLen(int a[], int b[], int len, int n)
{
    int i;
    for(i = 0; i+2*len-1 < n; i+=2*len)
    {
        mergeList(a, b, i, i+len-1, i+2*len-1);
    }
    if(i + len < n)
        mergeList(a, b, i, i+len-1, n-1);
    else
    {
        for(int j = i; j < n; j++)
            b[j] = a[j];
    }

}

int mergeSort(int a[], int b[], int n)
{

    int len = 1;
    while(len < n)
    {
        mergeLen(a, b, len, n);
        len *= 2;
        if(len >= n)
            return 2;
        mergeLen(b, a, len, n);
        len *= 2;
    }
    return 1;
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int tmp = mergeSort(arr, brr, n);

        int *a;
        if(tmp == 1)
            a = arr;
        else
            a = brr;
        printf("%d", a[n-1]);
        for(int i = n-2; i >= n-m; i--)
            printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}
