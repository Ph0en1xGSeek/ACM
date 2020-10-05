#include <iostream>
#include <queue>

using namespace std;
bool vis[100005] = {false};
struct point
{
    int pos;
    int len;
}now, nex;
queue<point> q;
int n, k;
int bfs()
{
    now.pos = n;
    now.len = 0;
    vis[n] = true;
    q.push(now);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            if(i == 0)
                nex.pos = now.pos + 1;
            else if(i == 1)
                nex.pos = now.pos - 1;
            else
                nex.pos = 2 * now.pos;
            nex.len = now.len + 1;
            if(nex.pos == k)
                return nex.len;
            if(nex.pos < 0 || nex.pos > 100001)
                continue;
            if(!vis[nex.pos])
            {
                vis[nex.pos] = true;
                q.push(nex);
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    if(n == k)
        cout << 0 << endl;
    else if(n > k)
        cout << n - k << endl;
    else
        cout << bfs() << endl;
    return 0;
}
