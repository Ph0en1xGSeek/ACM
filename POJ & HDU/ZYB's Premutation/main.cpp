#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int num;
int arr1[50005];
int arr[50005];

int lowbit(int x)
{
    return (x & (-x));
}

int getsum(int n)///计算有多少个比它大的
{
    int sum = 0;
    while(n > 0)
    {
        sum += arr[n];
         n -= lowbit(n);
    }
    return sum;
}

void update(int n, int val)
{
    while(n <= num)
    {
        arr[n] += val;
        n += lowbit(n);
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    int ans[50005];
    while(ca--)
    {
        scanf("%d", &num);
        memset(arr, 0, sizeof(arr));
        arr1[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &arr1[i]);
            update(i, 1);
        }
        for(int i = num; i > 0; i--)
            arr1[i] = i - (arr1[i] - arr1[i-1]);///i位及之前比i位上的数小的个数
        for(int i = num; i > 0; i--)
        {
            int l = 1, r = num;
            while(l < r)
            {
                int mid = (l+r)>>1;
                if(getsum(mid) >= arr1[i])
                    r = mid;
                else
                    l = mid+1;
            }
            ans[i] = l;
            update(ans[i], -1);
        }
        printf("%d", ans[1]);
        for(int i = 2; i <= num; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
