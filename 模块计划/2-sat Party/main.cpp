#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <stdio.h>
#define Max 2015

using namespace std;
int dfn[Max];
int low[Max];
int belong[Max];//属于哪个强连通分量
bool vis[Max];
int type, time;//type标记这是第几个强连通分量
vector<int> e[Max];//a出现，b一定出现,a+n为丈夫， a为妻子
int s[Max];
int top;

void tarjan(int x)
{
    dfn[x] = low[x] = ++time;
    vis[x] = 1;
    s[++top] = x;
    for(int i = 0; i < e[x].size(); i++)
    {
        int v = e[x][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v])
            low[x] = min(low[x], dfn[v]);
    }
    if(dfn[x] == low[x])
    {
        int tmp;
        do
        {
            tmp = s[top--];
            belong[tmp] = type;
            vis[tmp] = 0;
        }while(tmp != x);
        type++;
    }
}

int main()
{
    int n, m;
    int a, b, c, d;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        top = type = time = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 2*n; i++)
            e[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(c == 1 && d == 1)
            {
                e[a+n].push_back(b);
                e[b+n].push_back(a);
            }
            else if(c == 0 && d == 0)
            {
                e[a].push_back(b+n);
                e[b].push_back(a+n);
            }
            else if(c == 1 && d == 0)
            {
                e[a+n].push_back(b+n);
                e[b].push_back(a);
            }
            else if(c == 0 && d == 1)
            {
                e[a].push_back(b);
                e[b+n].push_back(a+n);
            }
        }
        for(int i = 0; i < 2*n; i++)
        {
            if(dfn[i] == 0)
                tarjan(i);
        }
        int flag = 1;
        for(int i = 0; i < n; i++)
            if(belong[i] == belong[i+n])
            {
                flag = 0;
                break;
            }
        if(!flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
