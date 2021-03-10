#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
long long arr[1001000];
int main()
{

    int n;
    long long tmp;
    int ans;
    while(~scanf("%d", &n))
    {
        ans = tmp = 0;
        for(int i  = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        tmp = arr[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            if(tmp >= 0)
            {
                tmp = arr[i];
                ans ++;
            }
            else
                tmp += arr[i];
        }
        if(tmp >=0) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
