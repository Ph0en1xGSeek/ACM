#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int id, num;
    bool operator<(const node& a)const
    {
        return num > a.num;
    }
}c[30];

int mp[6][6];
int ca, n, m, k, cc = 1;

bool dfs(int x, int y)
{
    if(x == n) return 1;
    if(y == m) return dfs(x+1, 0);
    for(int i = 1; i <= k; i++)
    {
        if(c[i].num == 0) continue;
        if(x && mp[x-1][y] == c[i].id) continue;
        if(y && mp[x][y-1] == c[i].id) continue;
        c[i].num--;
        mp[x][y] = c[i].id;
        if(dfs(x, y+1)) return true;
        c[i].num++;
    }
    return false;
}

int main()
{
    scanf("%d", &ca);
    while(ca--)
    {
        memset(mp, 0, sizeof(mp));
        printf("Case #%d:\n", cc++);
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &c[i].num);
            c[i].id = i;
        }
        sort(c+1, c+k+1);
        int mx = c[1].num;
        if(mx > (n*m+1)/2)
        {
            printf("NO\n");
            continue;
        }
        if(dfs(0, 0))
        {
            printf("YES\n");
            for(int i = 0; i < n; i++)
            {
                printf("%d", mp[i][0]);
                for(int j = 1; j < m; j++)
                    printf(" %d", mp[i][j]);
                printf("\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
