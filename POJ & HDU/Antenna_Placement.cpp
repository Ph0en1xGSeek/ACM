#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int mp[45][15];
int dir[4][2] = {0,-1,0,1,1,0,-1,0};
bool arr[500][500];
bool used[500];
int linker[500];
int cnt;

bool xyl(int i)//ĞÙÑÀÀûËã·¨
{
    for(int j = 1; j <= cnt; j++)
    {
        if(arr[i][j] && !used[j])
        {
            used[j] = 1;
            if(linker[j] == -1 || xyl(linker[j]))
            {
                linker[j] = i;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    char tmp;
    int ca, n, m;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(arr, false, sizeof(arr));
        memset(mp, 0, sizeof(mp));
        memset(linker, -1, sizeof(linker));
        cnt = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            getchar();
            for(int j = 1; j <= m; j++)
            {
                tmp = getchar();
                if(tmp == '*')
                    mp[i][j] = ++cnt;
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(mp[i][j])
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        if(mp[x][y])
                            arr[mp[i][j]][mp[x][y]] = true;
                    }
        int ans = 0;
        for(int i = 1; i <= cnt; i++)
        {
            memset(used, false, sizeof(used));
            if(xyl(i))
                ans++;
        }
        printf("%d\n", cnt-ans/2);
    }
    return 0;
}
