#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[10010];
int sum[10010];
int vis[10010];

int main()
{
    int n, from = 0, to = 1;
    int flag;
    arr[0] = sum[0] = 0;
    memset(vis, -1, sizeof(vis));
    vis[0] = 0;
    while(~scanf("%d", &n))
    {
        flag = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            sum[i] = (sum[i-1] + arr[i]) % n;
            if(flag == 0)
            {
                if(vis[sum[i]] != -1)
                {
                    from = vis[sum[i]];
                    to = i;
                    flag = 1;
                }
                else
                    vis[sum[i]] =  i;
            }
        }
        printf("%d\n", to - from);
        for(int i = from + 1; i <= to; i++)
            printf("%d\n", arr[i]);
    }

    return 0;
}
