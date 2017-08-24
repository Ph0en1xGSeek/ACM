#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[500][2];
int sum[500];

int main()
{
    int n, a, b;
    while(~scanf("%d%d%d", &n, &a, &b))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &arr[i<<1][0], &arr[i<<1][1]);
            arr[((i<<1)|1)][0] = arr[i<<1][1];
            arr[((i<<1)|1)][1] = arr[i<<1][0];
            sum[i<<1] = sum[(i<<1)|1] = arr[i<<1][0] * arr[i<<1][1];
        }
        int ans = 0;
        for(int i = 0; i < (n<<1); i++)
        {
            int j;
            if(i&1) j = i + 1;
            else j = i+2;
            for(; j < (n<<1); j++)
            {
                if(arr[i][0] + arr[j][0] <= a && max(arr[i][1], arr[j][1]) <= b)
                    ans = max(ans, sum[i]+sum[j]);
                else if(arr[i][1] + arr[j][1] <= b && max(arr[i][0], arr[j][0]) <= a)
                    ans = max(ans, sum[i]+sum[j]);
            }
        }
        if(n == 1)
        {
            ans = 0;
//            if((arr[0][0] <= a && arr[0][1] <= b) || arr[0][0] <= b && arr[0][1] <= a)
//                ans = sum[0];
        }
        printf("%d\n", ans);
    }
    return 0;
}
