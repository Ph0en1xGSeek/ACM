#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stdio.h>
#include <string.h>
using namespace std;
//int *q;

char str[100100];
int arr[100100];
int cnt;

int findMinIndex(int arr[], int beg, int endd) //[]
{
    if(beg > endd)
        return -1;
    int minv = arr[beg];
    int minIndex = beg;
    for(int i = beg + 1; i <= endd; ++i)
    {
        if(arr[i] < minv)
        {
            minv = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxIndex(int arr[], int beg, int endd) //[]
{
    if(beg > endd)
        return -1;
    int minv = arr[beg];
    int maxIndex = beg;
    for(int i = beg + 1; i <= endd; ++i)
    {
        if(arr[i] > minv)
        {
            minv = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}



void getRemain(int arr[], int siz, int k)
{
    int rev = 0, revIndex = -1;
    for(int i = siz - k; i < siz; ++i)
    {
        revIndex = findMinIndex(arr, revIndex + 1, i);
        if(revIndex == -1) break;
        str[cnt++] =  arr[revIndex] + '0';
    }
    str[cnt] = '\0';
}

void getRemain2(int arr[], int siz, int k)
{
    int rev = 0, revIndex = -1;
    for(int i = siz - k; i < siz; ++i)
    {
        revIndex = findMaxIndex(arr, revIndex + 1, i);
        if(revIndex == -1) break;
        str[cnt++] =  arr[revIndex] + '0';
    }
    str[cnt] = '\0';
}

int main()
{

    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        cnt = 0;
        scanf("%s %d", str, &num);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
            arr[i] = str[i] - '0';
        getRemain(arr, len, len - num);
        printf("%s\n", str);
        cnt = 0;
        getRemain2(arr, len, len - num);
        printf("%s\n", str);
    }


    return 0;
}
