#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

struct node
{
    int t, p;
    bool operator<(const node &a)const
    {
        return t < a.t;
    }
}arr[10010];

int main()
{
    int ca, num, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d %d", &arr[i].t, &arr[i].p);
        sort(arr, arr+num);
        double ans = -1.0;
        for(int i = 1; i < num; i++)
        {
            double tmp = (double)abs(arr[i].p-arr[i-1].p)/(arr[i].t - arr[i-1].t);
            if(tmp > ans)
                ans = tmp;
        }
        printf("Case #%d: %.2lf\n", cc++, ans);
    }
    return 0;
}
