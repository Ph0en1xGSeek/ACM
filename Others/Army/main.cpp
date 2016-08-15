#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX 105

using namespace std;

int used[MAX], linker[MAX];
bool mp1[MAX][MAX], mp2[MAX][MAX], mp3[MAX][MAX];
int m,n,k;

bool xyl(int i)
{
    for(int j = 1; j <= m; j++)
    {
        if(mp1[i][j] && !used[j])
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
    int ca, num, tmp;
    bool flag;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(linker, -1, sizeof(linker));
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        memset(mp3, 0, sizeof(mp3));
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            for(int j = 0; j < num; j++)
            {
                scanf("%d", &tmp);
                mp1[i][tmp] = true;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            for(int j = 0; j < num; j++)
            {
                scanf("%d", &tmp);
                mp2[i][tmp] = true;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &num);
            for(int j = 0; j < num; j++)
            {
                scanf("%d", &tmp);
                mp3[i][tmp] = true;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(mp1[i][j])
                {
                    flag = false;
                    for(int kk = 1; kk <= k; kk++)
                        if(mp2[i][kk] && mp3[j][kk])
                        {
                            flag = true;
                            break;
                        }
                    if(!flag) mp1[i][j] = false;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            memset(used, 0, sizeof(used));
            if(xyl(i))
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
