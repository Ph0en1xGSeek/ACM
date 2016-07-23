#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int arr[105][105];
int grid[10010][2];
int linker[10010];
int vis[10010];

int match(int now)
{
    for(int i = 1; i <= m; i++)
    {
        if(!vis[i] && arr[now][i])
        {
            vis[i] = 1;
            if(linker[i] == -1 || match(linker[i]))
            {
                linker[i] = now;
                return 1;
            }
        }
    }
    return 0;
}

int xyl()///·µ»Ø×î´óÆ¥Åä
{
    memset(linker, -1, sizeof(linker));
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(match(i))
            ans++;
    }
    return ans;
}

int main()
{
    int ca = 1, k;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d", &grid[i][0], &grid[i][1]);
            arr[grid[i][0]][grid[i][1]] = 1;
        }
        int ans = xyl();
        int cnt = 0;
        for(int i = 0; i < k; i++)
        {
            arr[grid[i][0]][grid[i][1]] = 0;
            int res = xyl();
            arr[grid[i][0]][grid[i][1]] = 1;
            if(res < ans)   cnt++;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", ca++, cnt, ans);

    }
    return 0;
}
