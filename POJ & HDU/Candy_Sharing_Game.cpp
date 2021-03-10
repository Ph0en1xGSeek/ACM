#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1010];

int main()
{
    int num, ans;
    while(~scanf("%d", &num) && num != 0)
    {
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        ans = 0;
        while(1)
        {
            int i;
            for(i  = 1; i < num; i++)
                if(arr[i-1] != arr[i])
                    break;
            if(i == num) break;
            ans++;
            int tmp = arr[num-1]/2;
            for(i = num-1; i > 0; i--)
            {
                arr[i] >>= 1;
                arr[i] += arr[i-1]>>1;
            }
            arr[0] >>= 1;
            arr[0] += tmp;
            for(i = 0; i < num; i++)
                if(arr[i]&1)
                    arr[i]++;
        }
        printf("%d %d\n", ans, arr[0]);
    }
    return 0;
}
