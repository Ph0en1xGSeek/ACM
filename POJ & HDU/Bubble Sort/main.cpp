#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 100010

using namespace std;

int a[100010];
int rightNum[100010];
int result[100010];
int arr[M];

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += arr[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x, int val)
{
    while(x <= M)
    {
        arr[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    int ca, num;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &a[j]);
        }
        for(int j = num-1; j >=0; j--)
        {
            rightNum[j] = j+getsum(a[j]-1);
            update(a[j], 1);
        }
        for(int j = 0; j < num; j++)
        {
            int leftNum = min(a[j]-1, j);
            result[a[j]-1] = rightNum[j] - leftNum;
        }
        printf("Case #%d:", i);
        for(int j = 0; j < num; j++)
            printf(" %d", result[j]);
        printf("\n");
    }
    return 0;
}
