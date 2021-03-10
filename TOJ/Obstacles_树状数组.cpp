#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[100010];

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += arr[n];
        n -= lowbit(n);
    }
    return sum;
}

void update(int n, int val)
{
    while(n <= 100000)
    {
        arr[n] += val;
        n += lowbit(n);
    }
}

int main()
{
    int query, num, n;
    int a, b;
    while(scanf("%d", &num) != EOF)
    {
        memset(arr, 0, sizeof(arr));
        while(num--)
        {
            scanf("%d", &n);
            update(n, 1);
        }
        scanf("%d", &query);
        while(query--)
        {
            scanf("%d%d", &a, &b);
            if(a > b)   swap(a, b);
            printf("%d\n", getsum(b) - getsum(a-1));
        }
    }
    return 0;
}
