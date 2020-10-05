#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100010

using namespace std;

double arr[M];
int l1, l2, r1, r2;

double ans(int x)
{
    if(r1 <= l2)
    {
        if(x <= r1-l1+1)
            return arr[l1+x-1];
        else
            return arr[l2+x-r1+l1-1-1];
    }
    else if(r1 <= r2)
    {
        if(x <= l2-l1)
            return arr[l1+x-1];
        else if(x > r1 - l1+1 + r1-l2+1)
            return arr[l2+x-r1+l1-1-1];
        else
            return arr[l2+(x-l2+l1+1)/2 - 1];
    }
    else
    {
        swap(r1, r2);
        if(x <= l2-l1)
            return arr[l1+x-1];
        else if(x > r1 - l1+1 + r1-l2+1)
            return arr[l2+x-r1+l1-1-1];
        else
            return arr[l2+(x-l2+l1+1)/2 - 1];
    }
}

int main()
{
    int ca, n, m, sum;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lf", &arr[i]);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if(l1 > l2)
            {
                swap(l1, l2);
                swap(r1, r2);
            }
            sum = r1-l1+r2-l2+2;
            if(sum &1)
                printf("%.1lf\n", ans(sum/2+1));
            else
                printf("%.1lf\n", (ans(sum/2) + ans(sum/2+1)) / 2.0);
        }
    }
    return 0;
}
