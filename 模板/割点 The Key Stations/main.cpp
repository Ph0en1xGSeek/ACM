#include <iostream>
#define Max 1002
#include <cstring>
#include <cstdio>

using namespace std;
bool map[Max][Max], flag[Max], isCut[Max];
int dep[Max], low[Max], depth, root, n;//root记录根节点的子节点数

void dfs(int m)
{
    dep[m] = depth;
    low[m] = depth;
    flag[m] = true;
    depth++;
    for(int i = 1; i <= n; i++)
    {
        if(map[m][i])
        {
            if(!flag[i])
            {
                dfs(i);
                low[m] = min(low[m], low[i]);
                if(low[i] >= dep[m] && m != 1)
                    isCut[m] = true;
                else if(m == 1)
                    root++;
            }
            else
                low[m] = min(low[m], dep[i]);
        }
    }
}

int main()
{
    int from, to;
    while(scanf("%d", &n), n)
    {
        memset(map, false, sizeof(map));
        memset(low, 0, sizeof(low));
        memset(isCut, false, sizeof(isCut));
        memset(flag, false, sizeof(flag));
        while(scanf("%d", &from), from)
        {
            while(getchar() != '\n')
            {
                scanf("%d", &to);
                map[from][to] = map[to][from] = true;
            }
        }
        depth = 1;
        root = 0;
        dfs(1);
        int ans = 0;
        if(root > 1)
        {
            ans++;
            isCut[1] = true;
        }
        for(int i = 2; i <= n; i++)
            if(isCut[i])
                ans++;
        printf("%d", ans);
        if(ans > 0)
        {
            int tmp = 0;
            printf(" ");
            for(int i = 1; i <= n; i++)
                if(isCut[i])
                {
                    tmp++;
                    printf("%d", i);
                    if(tmp != ans)
                        printf(" ");
                    else
                        printf("\n");
                }
        }
        else
            printf("\n");
    }
    return 0;
}
