#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int nex[100010];
int vis[100010];
char str[6];

bool flag;

int main()
{
    flag = false;
    int s1, s2;
    int num;
    int from, to;
    char ch;
    while(~scanf("%d%d%d", &s1, &s2, &num))
    {
        flag = false;
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < num; i++)
        {
            cin >> from >> ch >> to;
            nex[from] = to;
        }
        while(nex[s1] != -1)
        {
            vis[s1] = true;
            s1 = nex[s1];
        }
        while(nex[s2] != -1)
        {
            if(vis[s2] == true)
            {
                flag = true;
                break;
            }
            s2 = nex[s2];
        }

        if(flag == true)
        {
            str[5] = '\0';
            for(int i = 4; i >= 0; i--)
            {
                str[i] = s2%10 + '0';
                s2/=10;
            }
            printf("%s\n", str);
        }
        else
            printf("-1\n");

    }
    return 0;
}
