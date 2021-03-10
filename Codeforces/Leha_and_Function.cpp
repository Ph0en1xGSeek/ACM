#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100010

using namespace std;

int arr[M<<1];

struct node
{
    int num;
    int pos;
    bool operator<(const node & b) const
    {
        return num > b.num;
    }
}brr[M<<1];

int ans[M<<1];

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &brr[i].num);
            brr[i].pos = i;
        }
        sort(brr, brr+num);
        sort(arr, arr+num);
        for(int i = 0; i < num; i++)
        {
            ans[brr[i].pos] = arr[i];
        }
        for(int i = 0; i < num; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
