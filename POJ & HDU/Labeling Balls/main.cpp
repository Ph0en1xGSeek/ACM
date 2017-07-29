#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
#define M 205

using namespace std;
int g[M][M], out[M];//����
priority_queue<int> q;
int n, m, from, to;
int ans[M];

int main()
{
    int ca, i;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(g, 0, sizeof(g));
        memset(out, 0, sizeof(out));
        scanf("%d%d", &n, &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d%d", &from, &to);
            if(!g[from][to])
                out[from]++;
            g[from][to] = 1;
        }
        for(i = 1; i <= n; i++)
            if(out[i] == 0)//�յ�
                q.push(i);
        for(i = n; i >= 1; i--)//Ҫ�����n���𰸲����н�,�����л�
        {
            if(q.empty())
                break;
            int u = q.top();
            q.pop();
            ans[u] = i;//����
            for(int j = 1; j <= n; j++)
                if(g[j][u])
                {
                    g[j][u] = 0;
                    out[j]--;
                    if(out[j] == 0)
                        q.push(j);
                }
        }
        if(i)
            printf("-1\n");
        else
        {
            for(i = 1; i < n; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[n]);
        }
    }
    return 0;
}
