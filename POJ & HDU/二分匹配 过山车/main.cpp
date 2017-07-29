#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int arr[505][505];
int used[505], linker[505];
int m, n;
int ans;

bool match(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(arr[i][j] == 1 && !used[j])
        {
            used[j] = 1;
            if(linker[j] == -1 || match(linker[j]))
            {
                linker[j] = i;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k, x, y;

    while(scanf("%d", &k) && k)
    {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(linker, -1, sizeof(linker));
        scanf("%d %d", &m, &n);
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }
        for(int i = 1; i <= m; i++)
        {
            memset(used, 0, sizeof(used));
            if(match(i))
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
