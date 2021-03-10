#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[105];


int main() {

    int n, m;
    int l[105], prel;
    bool flag;
    int cnt;
    bool vis[105];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0;
        flag = true;
        memset(arr, 0, sizeof(arr));
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < m; i++)
        {
            scanf("%d", &l[i]);
        }
        for(int i = 1; i < m; i++)
        {
            prel = l[i-1];
            int tmp = l[i]-prel;
            if(tmp <= 0)
                tmp += n;
            if(arr[prel] == 0)
            {
                arr[prel] = tmp;
                cnt++;
                if(vis[arr[prel]] == false)
                    vis[arr[prel]] = true;
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if(arr[prel] != tmp)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false)
            printf("-1\n");
        else
        {
            for(int i = 1, j = 1; i <= n; i++)
            {
                if(arr[i] == 0)
                {
                    for(;j <= n; j++)
                    {
                        if(vis[j] == false)
                        {
                            arr[i] = j;
                            vis[j] = true;
                            break;
                        }
                    }
                }
            }
            for(int i = 1; i <= n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }
    return 0;
}