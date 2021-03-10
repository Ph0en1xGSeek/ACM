#include <iostream>
#define mod 1000000007
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[55];

int main()
{
    int ca, num;
    long long ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+num);
        ans = arr[0];
        for(int i = 1; i < num; i++)
        {
            if(arr[i] - i <= 0)
            {
                ans = 0;
                break;
            }
            ans = ((ans%mod )* (arr[i]-i));
        }
        printf("%lld\n", ans%mod);
    }
    return 0;
}
