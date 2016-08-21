#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 205
#define INF 999999

using namespace std;

int vis[M][M];
int dir[4][2] = {-1,0,0,1,1,0,0,-1};
char mp[M][M];
int st[18][2];
int cnt;
int n, m;

bool check(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

int countOne(int x)
{
    int sum = 0;
    while(x)
    {
        if(x&1)
            sum++;
        x >>= 1;
    }
    return sum;
}

bool add(int k)
{
    for(int i = 0; i < cnt; i++)
    {
        if(vis[st[i][0]][st[i][1]] != 2)
            vis[st[i][0]][st[i][1]] = 0;
    }
    for(int i = 0; i < cnt; i++)
        if((k >> i) & 1)
        {
            int x = st[i][0], y = st[i][1];
            if(check(x-1, y) && mp[x-1][y] == '#')
                return false;
            if(!vis[x-1][y])
                vis[x-1][y] = 1;
            if(check(x, y+1) && mp[x][y+1] == '#')
                return false;
            if(!vis[x][y+1])
                vis[x][y+1] = 1;
            if(!vis[x][y])
                vis[x][y] = 1;
        }
    for(int i = 0; i < cnt; i++)
        if(vis[st[i][0]][st[i][1]] == 0)
            return false;
    return true;
}

int main()
{
    while(~scanf("%d%d", &n, &m) && n != 0 && m != 0)
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i<= n; i++)
            scanf("%s", mp[i]+1);
        cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(mp[i][j] == '.')
                {
                    st[cnt][0] = i;
                    st[cnt++][1] = j;
                }
        if(cnt == 0)
        {
            puts("0");
            continue;
        }
        int num = (1<<cnt);
        int ans = INF;
        for(int i = 0; i < cnt; i++)///枚举特殊灯的位置
        {
            int x = st[i][0], y = st[i][1];
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < cnt; k++)
                    vis[st[k][0]][st[k][1]] = 0;
                if(check(x+dir[j][0], y+dir[j][1]) && mp[x+dir[j][0]][y+dir[j][1]] == '#')
                    continue;
                if(check(x+dir[(j+1)%4][0], y+dir[(j+1)%4][1]) && mp[x+dir[(j+1)%4][0]][y+dir[(j+1)%4][1]] == '#')
                    continue;
                vis[x+dir[j][0]][y+dir[j][1]] = 2;
                vis[x+dir[(j+1)%4][0]][y+dir[(j+1)%4][1]] = 2;
                vis[x][y] = 2;
                for(int k = 0; k < num; k++)
                {
                    if((k >> i) & 1)
                        continue;
                    if(add(k))
                        ans = min(ans, countOne(k)+1);
                }
            }
        }
        if(ans == INF)
            puts("-1");
        else
            printf("%d\n", ans);
    }
    return 0;
}
