#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    int cc = 1;
    bool flag;
    map<int, bool> mp;
    int arr[35][35];
    int ca, n, m;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = false;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &arr[i][j]);

        mp.clear();
        for(int i = 0; i < m; i++)
        {
            if(!mp[arr[0][i]])
                mp[arr[0][i]] = true;
            else
            {
                flag = true;
                break;
            }
        }
        mp.clear();
        for(int i = 0; i < m && !flag; i++)
        {
            if(!mp[arr[n-1][i]])
                mp[arr[n-1][i]] = true;
            else
            {
                flag = true;
                break;
            }
        }
        mp.clear();
        for(int i = 0; i < n && !flag; i++)
        {
            if(!mp[arr[i][0]])
                mp[arr[i][0]] = true;
            else
            {
                flag = true;
                break;
            }
        }
        mp.clear();
        for(int i = 0; i < n && !flag; i++)
        {
            if(!mp[arr[i][m-1]])
                mp[arr[i][m-1]] = true;
            else
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(int i = 0; i < n; i++)
                for(int j = 1; j < m; j++)
                    if(arr[i][j] == arr[i][j-1])
                    {
                        flag = true;
                        break;
                    }
        }
        if(!flag)
        {
            for(int i = 0; i < m; i++)
                for(int j = 1; j < n; j++)
                    if(arr[j][i] == arr[j-1][i])
                    {

                        flag = true;
                        break;
                    }
        }
        printf("Case #%d: ", cc++);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
