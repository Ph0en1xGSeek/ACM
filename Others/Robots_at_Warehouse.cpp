#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool mp[200005];
bool vis[200005];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int ux, uy, tx, ty;
int ans;
bool doubleDegree;
int n, m;

void dfs(int x, int y, int step)
{
    if(x == ux && y == uy && step > 2||x == tx && y == ty)
        ans++;
    if(vis[x*m-m+y] || ans > 2 || ans && doubleDegree)
        return;
    vis[x*m-m+y] = true;
    int r = 0;
    for(int i = 0; i < 4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx > 0 && xx <= n && yy > 0 && yy <= m && mp[xx*m-m+yy])
        {
            r++;
            if(r > 2)
                doubleDegree = true;
            dfs(xx, yy, step+1);
        }
    }
}

int main()
{
    char c;
    while(~scanf("%d%d ", &n, &m))
    {
        doubleDegree = false;
        ans = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            //getchar();
            for(int j = 1; j <= m; j++)
            {
                c = getchar();
                if(c != '#')
                    mp[i*m-m+j] = true;
                if(c == '1')
                    ux = i, uy = j;
                else if(c == '2')
                    tx = i, ty = j;
            }
            getchar();
        }
        dfs(ux, uy, 0);
        if(ans > 2 || ans&&doubleDegree)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}
