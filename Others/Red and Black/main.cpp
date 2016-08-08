#include <iostream>
#include <cstring>

using namespace std;
char arr[25][25];
bool mark[25][25];
int xy[4][2] = {1,0,-1,0,0,1,0,-1};
int total;
int w, h;

void dfs(int x, int y)
{
    mark[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int p = x + xy[i][0];
        int q = y + xy[i][1];
        if(p >= 0 && q >= 0 && p < w && q < h && !mark[p][q] && arr[p][q] != '#')
        {
            total++;
            dfs(p, q);
        }

    }
    return;
}


int main()
{
    int x, y;
    cin >> h >> w;
    while(w)
    {
        total = 1;
        memset(mark, false, sizeof(mark));
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y);
        cout << total << endl;

        cin >> h >> w;
    }

    return 0;
}
