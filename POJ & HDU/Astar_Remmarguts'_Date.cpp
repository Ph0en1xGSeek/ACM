#include<iostream>
#include <cstring>
#include <cstdio>
#include<queue>
#define MAXN 1001

using namespace std;

struct node
{
     int p,g,h;///g是到t的距离 h是s到这的距离
     bool operator < (node a) const
     {
          return a.g + a.h < g + h;
     }
};

struct node1
{
     int x, y, w, next;
}edge[MAXN*100], edge1[MAXN*100];

int n, m;
int head[MAXN], head1[MAXN], g[MAXN];
int s, e, k;
bool used[MAXN];
priority_queue<node> myqueue;

void djikstra()
{
    int i, k, p;
    memset(used, 0, sizeof(used));
    memset(g, 0x7F, sizeof(g));
    g[e] = 0;
    for(p = 1; p <= n; p++)
    {
        k = 0;
        for (i = 1; i <= n; i++)
            if (!used[i] && (!k || g[i] < g[k]))
                k=i;
        used[k]=true;
        k=head1[k];
        while (k)
        {
            if (g[edge1[k].y]>g[edge1[k].x]+edge1[k].w)
                g[edge1[k].y]=g[edge1[k].x]+edge1[k].w;
            k=edge1[k].next;
        }
    }
    return;
}
int Astar()
{
    ///其实就是枚举路径上的点，第k次出现终点就是第k长路的长度
     int t, times[MAXN];
     node h, temp;
     while (!myqueue.empty())  myqueue.pop();
     memset(times,0,sizeof(times));
     h.p = s;
     h.g = 0;
     h.h = 0;
     myqueue.push(h);
     while(!myqueue.empty())
     {
           h = myqueue.top();
           myqueue.pop();
           times[h.p]++;
           if (times[h.p] == k && h.p == e) return h.h + h.g;
           if (times[h.p] > k) continue;///剪枝，某个点出现了k+1次就不再往下搜
           t = head[h.p];
           while (t)
           {
                 temp.h = h.h + edge[t].w;
                 temp.g = g[edge[t].y];
                 temp.p = edge[t].y;
                 myqueue.push(temp);
                 t = edge[t].next;
           }
     }
     return -1;
}
int main()
{
     scanf("%d%d", &n, &m);
     memset(head, 0, sizeof(head));
     memset(head1, 0, sizeof(head1));
     for (int i = 1; i <= m; i++)
     {
          scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
          edge[i].next = head[edge[i].x];
          head[edge[i].x] = i;
          edge1[i].x = edge[i].y, edge1[i].y = edge[i].x;
          edge1[i].w = edge[i].w;
          edge1[i].next = head1[edge1[i].x];
          head1[edge1[i].x]= i;
     }
     scanf("%d%d%d",&s,&e,&k);
     if (s == e) k++;
     djikstra();
     printf("%d\n",Astar());
     return 0;
}
