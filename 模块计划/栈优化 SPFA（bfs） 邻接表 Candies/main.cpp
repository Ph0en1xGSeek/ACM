#include <iostream>
#define MAXN 30005
#define MAXM 150004
#define INF 1e9
#include <stack>
#include <cstring>
#include <stdio.h>

using namespace std;

struct node
{
    int to;
    int len;
    int nex;
}e[MAXM];

int n, m, head[MAXN] = {0}, dis[MAXN];
stack<int> s;
int vis[MAXN];

void spfa()
{
    dis[1] = 0;
    for(int i = 2; i <= n; i++)
        dis[i] = INF;
    s.push(1);
    vis[1] = 1;
    while(!s.empty())
    {
        int k = s.top();
        s.pop();
        for(int i = head[k]; i != 0; i = e[i].nex)
        {
            int to = e[i].to;
            if(dis[to] > dis[k] + e[i].len)
            {
                dis[to] = dis[k] + e[i].len;
                if(!vis[to])
                {
                    vis[to] = true;
                    s.push(to);
                }
            }
        }
        vis[k] = 0;
    }
}

int main()
{
    int a, b, c;
    scanf("%d%d", &n, &m);
    int k = 1;
    while(m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        e[k].to = b;
        e[k].len = c;
        e[k].nex = head[a];
        head[a] = k++;
    }
    spfa();
    printf("%d\n", dis[n]);
    return 0;
}
