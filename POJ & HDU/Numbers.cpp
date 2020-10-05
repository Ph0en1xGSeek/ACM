#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    bool flag;
    int num, arr[102];
    int vis[2016];
    while(~scanf("%d", &num))
    {
        flag = false;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            vis[arr[i]]++;
        }
        sort(arr, arr+num);
        for(int i = 1; i < num; i++)
        {
            vis[arr[i]]--;
            for(int j = 0; j < i; j++)
            {
                if(vis[arr[i]+arr[j]])
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
