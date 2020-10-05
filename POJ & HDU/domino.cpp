#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    long long n, k;
    long long arr[100010];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &k);
        for(int i = 0; i < n-1; i++)
            scanf("%lld", &arr[i]);
        if(k >= n)
        {
            printf("%lld\n", n);
            continue;
        }
        sort(arr, arr+n-1);
        long long ans = 0;
        for(int i = 0; i < n-k; i++)
            ans += arr[i] + 1;
        ans += k;
        printf("%lld\n", ans);
    }
    return 0;
}
