#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long arr[101000];
    int n, p;
    while(scanf("%d%d", &n, &p) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            arr[i] %= p;
        }
        sort(arr, arr+n);
        long long ans = (arr[n-1] + arr[n-2])%p;///不可能超过2p-2，即使超过p这也是最大情况
        for(int i = 0; i < n-1; i++)
        {
            long long tmp = arr[i];
            int left = i+1, right = n;
            while(left < right)///二分找与其相加小于p的最大值
            {
                int mid = (left + right) >> 1;
                if(tmp + arr[mid] < p)
                {
                    if(tmp + arr[mid] > ans)
                        ans = tmp + arr[mid];
                    left = mid+1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
