#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[2505][2505];
int arr[2505][2505];
bool vis[2505];

int main()
{
    int n, m;
    int mx;
    memset(arr, 0, sizeof(arr));
    while(~scanf("%d%d", &n, &m))
    {
        mx = max(n, m);
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%s", &str[i][1]);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                arr[i][j] = (str[i][j] - '0') + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }
        int mi = 1e8;
        for(int k = 2; k <= mx; k++)
        {
            int tmp;
            int ans = 0;
            if(vis[k])  continue;
            for(int kk = k+k; kk <= mx; kk += k)    vis[kk] = true;
            for(int x1 = 1; x1 <= n; x1 += k)
            {
                for(int y1 = 1; y1 <= m; y1 += k)
                {
                    int x2 = x1 + k - 1;
                    int y2 = y1 + k - 1;
                    if(x2 >= n)
                        x2 = n;
                    if(y2 >= m)
                        y2 = m;
                    tmp = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
                    tmp = min(tmp, k*k-tmp);
                    ans += tmp;
                }
            }
            mi = min(mi, ans);
        }
        printf("%d\n", mi);
    }
    return 0;
}
