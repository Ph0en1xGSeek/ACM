

#include <iostream>
#define Max 105
#include <stdio.h>
#include <cstring>

using namespace std;
int g[Max][Max];
int used[Max], linker[Max];
int n, m, k;

bool xyl(int i)//ĞÙÑÀÀûËã·¨
{
    for(int j = 0; j < m; j++)
    {
        if(g[i][j] && !used[j])
        {
            used[j] = 1;
            if(linker[j] == -1 || xyl(linker[j]))
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
    int t, x, y;
    int ans;
    while(scanf("%d", &n), n)
    {
        scanf("%d%d",  &m, &k);
        ans = 0;
        memset(g, 0, sizeof(g));
        memset(linker, -1, sizeof(linker));
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d %d", &t, &x, &y);
            if(x > 0 && y > 0)
                g[x][y] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            memset(used, 0, sizeof(used));
            if(xyl(i))
                ans++;
        }
        printf("%d\n", ans);

    }
    return 0;
}
