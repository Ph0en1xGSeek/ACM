#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100010];
    int ca, num, cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        int mx = 0;
        int ans;
        int sum = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i] > mx)
                mx = arr[i];
            sum += arr[i];
        }
        if(3*(sum-mx) + 2 >= mx)
            ans = (sum) / 2;
        else
            ans = (sum-mx) * 2 + 1;
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
