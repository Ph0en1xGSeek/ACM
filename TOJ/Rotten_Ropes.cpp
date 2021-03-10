#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int arr[1080];
    int ca, num, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+num);
        for(int i = 1; i <= num; i++)
        {
            if(arr[num-i]*i > ans)
                ans = arr[num-i]*i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
