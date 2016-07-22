#include <iostream>
#include <cstring>

using namespace std;
bool arr[40][40][40];
bool vis[40][40][40];
int ans;
struct point
{
    int level, row, colum;
    int len;
}s, e;

bool BFS(int a, int b, int c)
{
    int head = 0, tail = 0;
    point q[30000];
    q[0].level = a;
    q[0].row = b;
    q[0].colum = c;
    vis[a][b][c] = true;
    tail++;
    while(head < tail)
    {
        point x = q[head];
        head++;
        if(x.level == e.level && x.row == e.row && x.colum == e.colum)
        {
            ans = x.len;
            return true;
        }
        if(arr[x.level][x.row][x.colum+1] && !vis[x.level][x.row][x.colum+1])
        {
            vis[x.level][x.row][x.colum+1] = true;
            q[tail].level = x.level;
            q[tail].row = x.row;
            q[tail].colum = x.colum + 1;
            q[tail].len = x.len + 1;
            tail++;
        }
        if(arr[x.level][x.row][x.colum-1] && !vis[x.level][x.row][x.colum-1])
        {
            vis[x.level][x.row][x.colum-1] = true;
            q[tail].level = x.level;
            q[tail].row = x.row;
            q[tail].colum = x.colum - 1;
            q[tail].len = x.len + 1;
            tail++;
        }
        if(arr[x.level][x.row+1][x.colum] && !vis[x.level][x.row+1][x.colum])
        {
            vis[x.level][x.row+1][x.colum] = true;
            q[tail].level = x.level;
            q[tail].row = x.row + 1;
            q[tail].colum = x.colum;
            q[tail].len = x.len + 1;
            tail++;
        }
        if(arr[x.level][x.row-1][x.colum] && !vis[x.level][x.row-1][x.colum])
        {
            vis[x.level][x.row-1][x.colum] = true;
            q[tail].level = x.level;
            q[tail].row = x.row - 1;
            q[tail].colum = x.colum;
            q[tail].len = x.len + 1;
            tail++;
        }
        if(arr[x.level+1][x.row][x.colum] && !vis[x.level+1][x.row][x.colum])
        {
            vis[x.level+1][x.row][x.colum] = true;
            q[tail].level = x.level + 1;
            q[tail].row = x.row;
            q[tail].colum = x.colum;
            q[tail].len = x.len + 1;
            tail++;
        }
        if(arr[x.level-1][x.row][x.colum] && !vis[x.level-1][x.row][x.colum])
        {
            vis[x.level-1][x.row][x.colum] = true;
            q[tail].level = x.level - 1;
            q[tail].row = x.row;
            q[tail].colum = x.colum;
            q[tail].len = x.len + 1;
            tail++;
        }
    }
    return false;
}

int main()
{
    int a, b, c;
    char ch;
    while(cin >> a >> b >> c && a)
    {
        memset(arr, false, sizeof(arr));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                for(int k = 1; k <= c; k++)
                {
                    cin >> ch;
                    if(ch == '.')
                        arr[i][j][k] = true;
                    else if(ch == 'S')
                    {
                        arr[i][j][k] = true;
                        s.level = i;
                        s.row = j;
                        s.colum = k;
                        s.len = 0;
                    }
                    else if(ch == 'E')
                    {
                        arr[i][j][k] = true;
                        e.level = i;
                        e.row = j;
                        e.colum = k;
                    }
                }
            }
        }
        if(BFS(s.level, s.row, s.colum))
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;

    }
    return 0;
}
