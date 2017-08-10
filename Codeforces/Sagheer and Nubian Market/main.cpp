#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100005

using namespace std;

long long arr[M];
long long tmp[M];

int main()
{
    int n;
    long long s;
    while(~scanf("%d%I64d", &n, &s))
    {
        arr[0] = 0;
        for(int i = 1 ; i <= n; i++)
        {
            scanf("%I64d", &arr[i]);
        }
        int l = 1;
        int r = n;
        int ans;
        long long sum = 0;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            for(int i = 1; i <= n; i++)
                tmp[i] = arr[i] + (long long)i*mid;
            sort(tmp+1, tmp+1+n);
            sum = 0;
            for(int i = 1; i <= mid; i++)
                sum += tmp[i];
            if(sum > s)
                r = mid-1;
            else if(sum < s)
                l = mid + 1;
            else
            {
                ans  = mid;
                break;
            }
            ans = r;
        }
        for(int i = 1; i <= n; i++)
            tmp[i] = arr[i] + (long long)i*ans;
        sort(tmp+1, tmp+1+n);
        sum = 0;
        for(int i = 1; i <= ans; i++)
            sum += tmp[i];
        printf("%d %I64d\n", ans, sum);
    }
    return 0;
}
