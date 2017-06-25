#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define M 50000

using namespace std;

struct edge
{
    int des;
    int len;
};

struct node
{
    int cur;
    int dis;
};

vector<edge> arr[M];
bool vis[M];
int ans, mx;

void bfs(int v)
{
    mx = 0;
    queue<node> q;
    memset(vis, 0, sizeof(vis));
    vis[v] = true;
    node tmp, tmp2;
    tmp.dis = 0;
    tmp.cur = v;
    q.push(tmp);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        int u = tmp.cur;
        for(int i = 0; i < arr[u].size(); i++)
        {
            if(!vis[arr[u][i].des])
            {
                vis[arr[u][i].des] = true;
                tmp2.cur = arr[u][i].des;
                tmp2.dis = arr[u][i].len + tmp.dis;
                if(tmp2.dis > mx)
                {
                    mx = tmp2.dis;
                    ans = tmp2.cur;
                }
                q.push(tmp2);
            }
        }
    }
}

int main()
{
    int n, m;
    char ch;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int a, b, c;
        for(int i = 1; i <= n; i++) arr[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            ch = getchar();
            ch = getchar();
            edge tmp;
            tmp.des = b;
            tmp.len = c;
            arr[a].push_back(tmp);
            tmp.des = a;
            arr[b].push_back(tmp);
        }
        bfs(1);
        bfs(ans);
        printf("%d\n", mx);
    }
    return 0;
}
