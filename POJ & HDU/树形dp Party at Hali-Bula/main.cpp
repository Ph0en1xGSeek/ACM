#include <iostream>
#define M 405
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;
int cnt, cnt2;
int dp[M][2];///第i个人0不参加/1参加时的最大人数
int isDuplicate[M][2];///上述情况时是否存在多个解
map<string, int> m;

struct node
{
    int v;
    int next;
}e[M];
int head[M];

void addedge(int u, int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    isDuplicate[u][0] = 0;
    isDuplicate[u][1] = 0;

    for(int i = head[u]; i != -1;i = e[i].next)
    {
        int v = e[i].v;
        dfs(v);
        dp[u][1] += dp[v][0];
        if(isDuplicate[v][0] == 1)  isDuplicate[u][1] = 1;
        if(dp[v][0] > dp[v][1])
        {
            dp[u][0] += dp[v][0];
            if(isDuplicate[v][0] == 1)
                isDuplicate[u][0] = 1;
        }
        else if(dp[v][0] < dp[v][1])
        {
            dp[u][0] += dp[v][1];
            if(isDuplicate[v][1] == 1)
                isDuplicate[u][0] = 1;
        }
        else
        {
            dp[u][0] += dp[v][0];
            isDuplicate[u][0] = 1;
        }
    }
}

int main()
{
    int num;
    int u, v;
    string str1, str2;
    while(scanf("%d", &num) && num)
    {
        memset(head, -1, sizeof(head));
        memset(isDuplicate, 0, sizeof(isDuplicate));
        m.clear();
        cnt = cnt2 = 0;
        cin >> str1;
        m[str1] = ++cnt2;

        for(int i = 1; i < num; i++)
        {
            cin >> str1 >> str2;
            if(m[str1] == 0)
                m[str1] = ++cnt2;
            if(m[str2] == 0)
                m[str2] = ++cnt2;
            addedge(m[str2], m[str1]);
        }

        dfs(1);
        if(dp[1][0] > dp[1][1])
        {
            if(!isDuplicate[1][0])
                printf("%d Yes\n", dp[1][0]);
            else
                printf("%d No\n", dp[1][0]);
        }
        else if(dp[1][1] > dp[1][0])
        {
            if(!isDuplicate[1][1])
                printf("%d Yes\n", dp[1][1]);
            else
                printf("%d No\n", dp[1][1]);
        }
        else
            printf("%d No\n", dp[1][1]);
    }
    return 0;
}
