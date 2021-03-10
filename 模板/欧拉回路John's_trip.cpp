#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>

using namespace std;
int g[46][2000], degree[46];
bool vis[2000];
int num;
stack<int> st;

void euler(int u)
{
    for(int i = 0; i <= num; i++)
        if(g[u][i] && !vis[i])
        {
            vis[i] = true;
            euler(g[u][i]);
            st.push(i);
        }
}

int main()
{
    int x, y, z, first, i;
    while(scanf("%d%d", &x, &y) && (x != 0 || y != 0))
    {
        num = 0;
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        memset(degree, 0, sizeof(degree));
        scanf("%d", &z);
        g[x][z] = y;
        g[y][z] = x;
        degree[x]++;
        degree[y]++;
        first = min(x, y);
        num = max(num, z);
        while(scanf("%d%d", &x, &y) && (x != 0 || y != 0))
        {
            scanf("%d", &z);
            g[x][z] = y;
            g[y][z] = x;
            degree[x]++;
            degree[y]++;
            num = max(num, z);
        }
        for(i = 1; i <= 45; i++)
        {
            if(degree[i] & 1)
                break;
        }
        if(i <= 45)
            printf("Round trip does not exist.\n\n");
        else
        {
            euler(first);
            int flag = 1;
            while(!st.empty())
            {
                if(flag == 1)
                {
                    flag = 0;
                    printf("%d", st.top());
                    st.pop();
                }
                else
                {
                    printf(" %d", st.top());
                    st.pop();
                }
            }
            printf("\n\n");
        }
    }
    return 0;
}
