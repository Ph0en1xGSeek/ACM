#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[12][15];
int p[12], cur[12];
int ans, tmp, sum;
int n, k;

int main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    while(~scanf("%d%d", &n, &k))
    {
        tmp = ans = 0;
        memset(cur, 0, sizeof(cur));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
            for(int j = 0; j < p[i]; j++)
                scanf("%d", &arr[i][j]);
        }
        while(tmp < k)
        {
            for(int i = 0; i < n; i++)
            {
                if(cur[i] < p[i])
                {
                    if(arr[i][cur[i]] >= ans)
                    {
                        ans += arr[i][cur[i]];
                        cur[i]++;
                        tmp++;
                    }
                    else
                        cur[i]++;
                }
                else
                {
                    ans += 50;
                    tmp++;
                }
                if(tmp == k)
                    break;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}
