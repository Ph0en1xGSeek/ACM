#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int to;///边终点
    int cap;///边权
    friend bool operator <(const Edge &a, const Edge &b)
    {
        if(a.cap == b.cap) return a.to > b.to;///小的优先
        return a.cap < b.cap;///大的优先
    }
};

priority_queue<Edge> q;
bool vis[500010];

int main()
{
    int ca;
    int n, s, m;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(vis, false, sizeof(vis));
        while(!q.empty())
            q.pop();
        scanf("%d%d%d", &n, &s, &m);
        Edge tmp;
        vis[s] = true;
        printf("%d", s);
        if(s>>1)
        {
            tmp.to = (s>>1);
            tmp.cap = (s - tmp.to)%m;
            q.push(tmp);
        }
        if((s<<1) <= n)
        {
            tmp.to = (s<<1);
            tmp.cap = (tmp.to - s)%m;
            q.push(tmp);
        }
        if(((s<<1)|1) <= n)
        {
            tmp.to = (s<<1)|1;
            tmp.cap = (tmp.to - s)%m;
            q.push(tmp);
        }
        while(!q.empty())
        {
            tmp = q.top();
            q.pop();
            s = tmp.to;
            vis[s] = true;
            printf(" %d", s);
            if(s>>1 && !vis[s>>1])
            {
                tmp.to = (s>>1);
                tmp.cap = (s - tmp.to)%m;
                q.push(tmp);
            }
            if((s<<1) <= n && !vis[s<<1])
            {
                tmp.to = (s<<1);
                tmp.cap = (tmp.to - s)%m;
                q.push(tmp);
            }
            if(((s<<1)|1) <= n && !vis[(s<<1)|1])
            {
                tmp.to = (s<<1)|1;
                tmp.cap = (tmp.to - s)%m;
                q.push(tmp);
            }
        }
        printf("\n");
    }
    return 0;
}
