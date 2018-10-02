#include <iostream>
#include <stdio.h>
#include <cstring>
#define Max 105
#define INF 10e8
#include <queue>

using namespace std;
int n, np, nc, m;//�ܵ�������վ���õ�վ����
int flow[Max][Max], cap[Max][Max];
int exp[Max], pre[Max];//����������ǰһ����

int maxFlow(int start, int tail)
{
    memset(flow, 0, sizeof(flow));
    int ans = 0;
    int from, to;
    while(1)
    {
        memset(exp, 0, sizeof(exp));
        queue<int> q;
        q.push(start);
        exp[start] = INF;//����Դ�������
        while(!q.empty())
        {
            from = q.front();
            q.pop();
            for(to = 0; to <= tail; to++)
            {
                if(exp[to] == 0 && cap[from][to] > flow[from][to])//��ʱ��expֻ���ڱ���Ƿ��߹�
                {
                    pre[to] = from;
                    exp[to] = min(exp[from], cap[from][to] - flow[from][to]);
                    q.push(to);
                }
            }
        }
        if(exp[tail] == 0)
            break;
        for(int i = tail; i != start; i = pre[i])
        {
            flow[pre[i]][i] += exp[tail];
            flow[i][pre[i]] -= exp[tail];
        }
        ans += exp[tail];
    }
    return ans;
}

int main()
{
    int from, to, cost;
    while(scanf("%d %d %d %d ", &n, &np, &nc, &m) != EOF)
    {
        memset(cap, 0, sizeof(cap));
        for(int i = 0; i < m; i++)
        {
            scanf(" (%d,%d)", &from, &to);
            scanf("%d", &cap[from][to]);
        }
        for(int i = 0; i < np; i++)
        {
            scanf(" (%d)%d", &from, &cost);
            cap[n][from] = cost;//nΪ����Դ��
        }
        for(int i = 0; i < nc; i++)
        {
            scanf(" (%d)%d", &from, &cost);
            cap[from][n+1] = cost;//n+1Ϊ�������
        }
        int ans = maxFlow(n, n+1);
        printf("%d\n", ans);
    }
    return 0;
}
