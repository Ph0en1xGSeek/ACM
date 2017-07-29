#include <iostream>
#define Max 1002
#include <cstdio>
#include <cstring>

using namespace std;
int arr[Max][Max];
int vis[Max][Max];
int qstep[8][2] = {{1,0},{1,1},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
int kstep[8][2] = {{2,1},{1,2},{-2,1},{-1,2},{1,-2},{2,-1},{-2,-1},{-1,-2}};
int xy[100][2];

int main()
{
    int ca = 1;
    int m, n;
    int q, k, x, y, tmpx, tmpy;
    int ans;
    while(scanf("%d%d", &m, &n) != EOF, m|n)
    {
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &x, &y);
            xy[i][0] = x;
            xy[i][1] = y;
            arr[x][y] = 1;
        }

        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d", &x, &y);
            arr[x][y] = 1;
            for(int j = 0; j < 8; j++)
            {
                tmpx = x + kstep[j][0];
                tmpy = y + kstep[j][1];
                if((tmpx > 0 && tmpy > 0) && (tmpx <= m && tmpy <= n))
                    vis[tmpx][tmpy] = 1;
            }
        }
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d", &x, &y);
            arr[x][y] = 1;
        }

        for(int i = 0; i < q; i++)
        {
            x = xy[i][0];
            y = xy[i][1];
            for(int j =0; j < 8; j++)
            {
                tmpx = x;
                tmpy = y;
                tmpx += qstep[j][0];
                tmpy += qstep[j][1];
                while((tmpx > 0 && tmpy > 0) && (tmpx <= m && tmpy <= n))
                {
                    if(arr[tmpx][tmpy] == 0)
                    {
                        vis[tmpx][tmpy] = 1;
                    }
                    else if(arr[tmpx][tmpy] == 1)
                        break;
                    tmpx += qstep[j][0];
                    tmpy += qstep[j][1];
                }

            }
        }
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(vis[i][j]==0 && arr[i][j] == 0)
                    ans++;
        printf("Board %d has %d safe squares.\n", ca++, ans);
    }
    return 0;
}
