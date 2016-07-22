#include <iostream>
#define M 6003
#include <stdio.h>
#include <string.h>

using namespace std;
int rate[M], in[M], cnt;
int dp[M][2];///第i个人0不参加/1参加时的做大活跃度
struct node
{
    int v;
    int next;
}e[M<<1];
int head[M];

void addedge(int u, int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = rate[u];
    for(int i = head[u]; i != -1;i = e[i].next)
    {
        int v = e[i].v;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    return max(dp[u][0], dp[u][1]);
}

int main()
{
    int num;
    int u, v;
    while(scanf("%d", &num) != EOF)
    {
        memset(in, 0, sizeof(in));
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i <= num; i++)
            scanf("%d", &rate[i]);
        while(scanf("%d%d", &v, &u) && v != 0)
        {
            addedge(u, v);
            in[v]++;
        }
        int ans = 0;
        for(int i = 1; i <= num; i++)
            if(in[i] == 0)
                ans += dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}
