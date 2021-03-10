#include <iostream>
#include <cstdio>
#define INF 100000
#include <cstring>

using namespace std;
int common[15], critical[15], used[15];
int ans, cost;
int N, M;

void dfs(int n, int m)
{
    if(m <= 0)
    {
        ans = min(ans, cost);
        return;
    }
    else if(n == 0)
        return;
    cost++;
    for(int i = 0; i < N; i++)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            if(m <= critical[i])
                dfs(n-1, m-2*common[i]);
            else
                dfs(n-1, m-common[i]);
            used[i] = 0;
        }
    }
    cost--;
}

int main()
{

    while(scanf("%d%d", &N, &M) != EOF)
    {
        memset(used, 0, sizeof(used));
        ans = INF;
        cost = 0;//用了几张符文
        for(int i = 0; i < N; i++)
            scanf("%d%d", &common[i], &critical[i]);
        dfs(N, M);
        if(ans > 15)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
