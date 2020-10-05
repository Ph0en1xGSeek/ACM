#include <iostream>
#include <queue>

using namespace std;
char grid[101][101];
int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int m, n;
class point
{
    public:
    int x, y;
    point(){}

    point(int a, int b)
    {
        x = a;
        y = b;
    }
};
point tmp;
queue<point> q;

void dfs(int x, int y)
{
    int xx, yy;
    for(int i = 0; i < 8; i++)
    {
        xx = x + step[i][0];
        yy = y + step[i][1];
        if(xx >= 0 && yy >= 0 && xx < m && yy < n && grid[xx][yy] == '@')
        {
            grid[xx][yy] = '*';
            dfs(xx, yy);
        }
    }
}

int main()
{
    int ans;
    while(cin >> m >> n && m)
    {
        ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '@')
                    q.push(point(i, j));
            }
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            if(grid[tmp.x][tmp.y] == '@')
            {
                ans++;
                dfs(tmp.x, tmp.y);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
