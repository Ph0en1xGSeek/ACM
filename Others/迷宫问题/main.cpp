#include <iostream>
#include <queue>

using namespace std;
struct point
{
    int x, y;
}now, nex, tmp;
int step[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int arr[7][7];
point pre[7][7];

void bfs(int a, int b)
{
    queue<point> q;
    now.x = a;
    now.y = b;
    q.push(now);
    arr[now.x][now.y] = -1;
    while(!q.empty())
    {
        now = q.front();
        q.pop();


        for(int i = 0; i < 4; i++)
        {
            nex.x = now.x + step[i][0];
            nex.y = now.y + step[i][1];
            if(nex.x == 5 && nex.y == 5)
            {
                pre[5][5] = now;
                return;
            }
            if(arr[nex.x][nex.y] == 0)
            {
                q.push(nex);
                arr[nex.x][nex.y] = -1;
                pre[nex.x][nex.y] = now;
            }
        }
    }
}

void print(point n)
{
    if(n.x == 1 && n.y == 1)
        cout << "(0, 0)" << endl;
    else
    {
        print(pre[n.x][n.y]);
        cout << '(' << n.x-1 << ", " << n.y-1 << ')' << endl;
    }
}

int main()
{
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
        {
            arr[i][j] = -1;
            pre[i][j].x = -1;
            pre[i][j].y = -1;
        }
    for(int i = 1; i < 6; i++)
        for(int j = 1; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    bfs(1, 1);
    tmp.x = 5;
    tmp.y = 5;
    print(tmp);
    return 0;
}
