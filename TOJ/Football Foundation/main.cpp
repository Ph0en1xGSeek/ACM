#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char mp[200][200];
int arr[200][200];

int main()
{
    bool flag;
    int r, c, n;
    int x, y, step;
    while(scanf("%d%d%d", &r, &c, &n), r)
    {
        memset(mp, 0, sizeof(mp));
        memset(arr, 0, sizeof(arr));
        flag = false;
        for(int i = 1; i <= r; i++)
            scanf("%s", &mp[i][1]);
        x = 1, y = n, step = 1;
        while(mp[x][y])
        {
            //cout << x << ' ' << y << endl;
            if(arr[x][y])
                break;
            else
                arr[x][y] = step;
            if(mp[x][y] == 'W')
                y--;
            else if(mp[x][y] == 'S')
                x++;
            else if(mp[x][y] == 'E')
                y++;
            else if(mp[x][y] == 'N')
                x--;
            step++;
        }
        if(mp[x][y])
            printf("%d step(s) before a loop of %d step(s)\n", arr[x][y]-1, step-arr[x][y]);
        else
            printf("%d step(s) to exit\n", step-1);
    }
    return 0;
}
