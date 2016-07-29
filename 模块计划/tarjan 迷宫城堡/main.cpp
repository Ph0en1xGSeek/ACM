#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define Max 10007

using namespace std;

stack<int> s;
vector<int> e[Max];//�����������飬����ÿ���㿪ʼ�ı�
int vis[Max];//��Ҫʱ���Ա�Ƕ���״̬
int dfn[Max];
int low[Max];
int time, counts;

void tarjan(int x)
{
    dfn[x] = low[x] = ++time;
    vis[x] = 1;
    s.push(x);
    int len = e[x].size();
    for(int i = 0; i < len; i++)
    {
        int v = e[x][i];
        if(!vis[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v] == 1)///v����ջ�� ������ջ����Ϊǿ��ͨ����֮��ı�
            low[x] = min(low[x], dfn[v]);
    }
    if(dfn[x] == low[x])///��xΪ����������һ��ǿ��ͨ����
    {
        int tmp;
        counts++;
        do
        {
            tmp = s.top();
            s.pop();
        }while(tmp != x);
    }
}

int main()
{
    int n, m;
    int a, b;
    while(cin >> n >> m && n != 0)
    {
        time = counts = 0;
        memset(vis, 0, sizeof(vis));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        for(int i = 0; i < Max; i++)
            e[i].clear();
        while(!s.empty())
            s.pop();
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            e[a].push_back(b);
        }
        for(int i = 1; i <= n; i++)
            if(dfn[i] == 0)
                tarjan(i);
        if(counts == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
