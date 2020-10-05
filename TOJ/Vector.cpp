#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr1[11], arr2[11];
    int ca, d, ans;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d", &d);
        for(int i = 0; i < d; i++)
            scanf("%d", &arr1[i]);
        for(int i = 0; i < d; i++)
            scanf("%d", &arr2[i]);
        for(int i = 0; i < d; i++)
            ans += arr1[i]*arr2[i];
        printf("%d\n", ans);
    }
    return 0;
}
