#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector<int> arr[100040];
bool vis[100010];

double dfs(int x)
{
    vis[x] = true;
    int len = arr[x].size();
    if(len == 1) return 0.0;
    double ans = 0;
    for(int i = 0; i < len; i++)
    {
        if(vis[arr[x][i]]) continue;
        ans += (double)dfs(arr[x][i])/(len-1.0);
    }
    return ans + 1.0;
}

int main()
{
    int num;
    int a, b;
    while(~scanf("%d", &num))
    {
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        for(int i = 1; i <= num; i++)
            arr[i].clear();
        arr[1].push_back(0);
        for(int i = 0; i < num-1; i++)
        {
            scanf("%d%d", &a, &b);
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        double ans = dfs(1);
        printf("%.15lf\n", ans);
    }
    return 0;
}
