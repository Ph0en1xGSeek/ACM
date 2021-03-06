#include <iostream>
#include <stdio.h>
#define N 100

using namespace std;

void bubbleSort(int a[], int n)
{
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        for(int i = low; i < high; i++)
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        high--;
        for(int i= high; i > low; i--)
            if(a[i] > a[i-1])
                swap(a[i], a[i-1]);
        low++;
    }
}

struct node
{
    int key;
    int numLess;
};

void countSort(node arr1[], node arr2[], int n)
{
    int cnt;
    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        for(int j = 0; j < n; j++)
            if(arr1[i].key > arr1[j].key)   cnt++;
        arr1[i].numLess = cnt;
    }
    for(int i = 0; i < n; i++)
    {
        int num = arr1[i].numLess;
        arr2[num].key = arr1[i].key;
        arr2[num].numLess = num;
    }
}

struct elem
{
    int key;
    int next;
}elems[N+1];

struct linkList
{
    int first;
    int tail;
}arr[10];

int radixSort(elem elems[], int n)
{
    for(int i = 1; i < n; i++)
        elems[i].next = i+1;
    elems[n].next = -1;
    for(int i = 0; i <= 9; i++)
        arr[i].first = arr[i].tail = -1;
    int p = 1, k;
    while(p != -1)
    {
        k = elems[p].key;
        if(arr[k].first == -1)  arr[k].first = p;
        else    elems[arr[k].tail].next = p;
        arr[k].tail = p;
        p = elems[p].next;
    }
    int i = 0;
    while(arr[i].first == -1)   i++;
    int t = arr[i].tail;
    p = arr[i].first;
    while(i < 9)
    {
        i++;
        if(arr[i].first != -1)
        {
            elems[t].next = arr[i].first;
            t = arr[i].tail;
        }
    }
    elems[t].next = -1;
    return p;
}

int main()
{

    return 0;
}
