#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define M 55
#define INF 999999

using namespace std;

double mp[M][M];
bool vis[M];
double dis[M];
int nike, apple;
int num;

double dist(int x1, int y1, int x2, int y2)
{
    double ans = (double)((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return sqrt(ans);
}

struct node
{
    int x, y;
}arr[M];

double prim()
{
    double sum = 0;
    sum += mp[nike][apple];
    vis[nike] = vis[apple] = true;
    for(int i = 1; i <= num; i++)
        dis[i] = min(mp[apple][i], mp[nike][i]);
    for(int i = 0; i < num; i++)
    {
        int tmp = -1;
        double mi = INF*1.0;
        for(int j = 1; j <= num; j++)
            if(!vis[j] && mi > dis[j])
            {
                tmp = j;
                mi = dis[j];
            }
        if(tmp == -1)
            return sum;
        vis[tmp] = true;
        sum += mi;
        for(int j = 1; j <= num; j++)
            if(vis[j] == false && dis[j] > mp[tmp][j])
                dis[j] = mp[tmp][j];
    }
    return sum;
}

int main()
{
    while(~scanf("%d", &num) && num != 0)
    {
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &apple, &nike);
        for(int i = 1; i <= num; i++)
            scanf("%d%d", &arr[i].x, &arr[i].y);
        for(int i = 1; i <= num; i++)
            for(int j = 1; j <= num; j++)
                if(i != j)
                    mp[i][j] = dist(arr[i].x, arr[i].y, arr[j].x, arr[j].y);
                else
                    mp[i][j] = INF*1.0;
        double ans = prim();
        printf("%.2f\n", ans);
    }
    return 0;
}
