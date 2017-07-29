#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    long long arr1[820], arr2[820];
    int ca, num, c = 1;
    long long total;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        total = 0;
        for(int i = 0; i < num; i++)
            scanf("%lld", &arr1[i]);
        for(int i = 0; i < num; i++)
            scanf("%lld", &arr2[i]);
        sort(arr1, arr1 + num);
        sort(arr2, arr2 + num);
        for(int i = 0; i < num; i++)
            total += arr1[i] * arr2[num-i-1];
        printf("Case #%d: %lld\n", c++, total);

    }
    return 0;
}
