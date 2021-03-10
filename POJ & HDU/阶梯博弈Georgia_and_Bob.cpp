#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[1005];
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        arr[0] = 0;///别忘了最左边不为1的情况
        for(int i = 1; i <= num; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+num+1, cmp);
        int ans = 0;
        for(int i = 1; i <= num; i+=2)
        {
            ans ^= (arr[i-1] - arr[i])-1;
        }
        if(ans)
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
