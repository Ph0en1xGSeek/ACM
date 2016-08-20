#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;

map<string, int> m;
vector<int> arr[1010];
bool vis[1010];
int dis[1010];
int mx;
int num, n;

int bfs(int i)
{
    int tmp;
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int dp = 0;
    int m = 0;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        dp++;
        int siz = arr[tmp].size();
        for(int j = 0; j < siz; j++)
        {
            if(vis[arr[tmp][j]])
                continue;
            else
            {
                vis[arr[tmp][j]] = true;
                q.push(arr[tmp][j]);
                dis[arr[tmp][j]] = dis[tmp]+1;
                if(dis[arr[tmp][j]] > m)
                    m = dis[arr[tmp][j]];
            }
        }
    }
    if(dp == num)
        return m;
    else
        return -1;
}

int main()
{
    bool flag;
    string str, str1;
    while(~scanf("%d", &num) && num != 0)
    {
        flag = true;
        mx = 0;
        m.clear();
        for(int i = 0; i < num; i++)
            arr[i].clear();
        for(int i = 0; i < num; i++)
        {
            cin >> str;
            m[str] = i;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            cin >> str >> str1;
            arr[m[str]].push_back(m[str1]);
            arr[m[str1]].push_back(m[str]);
        }
        for(int i = 0; i < num; i++)
        {
            int tmp = bfs(i);
            if(tmp == -1)
            {
                flag = false;
                break;
            }
            mx = max(tmp, mx);
        }
        if(flag)
            printf("%d\n", mx);
        else
            printf("-1\n");
    }
    return 0;
}
