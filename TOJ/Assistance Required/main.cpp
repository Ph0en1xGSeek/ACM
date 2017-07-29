#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 50000

using namespace std;

bool vis[M];
int arr[M];
int cnt;

int main()
{
    memset(vis, false, sizeof(vis));
    memset(arr, 0, sizeof(arr));
    int k, j;
    arr[0] = 1;
    for(int i = 1; i <= 3000; i++)
    {
        for(j = arr[i-1] + 1; vis[j]; j++);
        arr[i] = j;
        cnt = j;
        for(k = j+1; k < M; k++)
            if(!vis[k] && !(--cnt))
            {
                vis[k] = true;
                cnt = j;
            }
    }

    int num;
    while(scanf("%d", &num) && num != 0)
    {
        printf("%d\n", arr[num]);
    }
    return 0;
}
