#include <iostream>
#include <cstdio>
#include <cstring>
#define N 102

using namespace std;
int arr[N][N];
int cut[N][N];//从这一点最多能走多少步
int num;

int dfs(int x, int y, int ans)
{
    int tmp = ans;
    for(int i = 1; i < x-1; i++)
    {
        if(arr[i][y-1] > arr[x][y])
        {
            if(cut[i][y-1])
                tmp = max(tmp, ans + cut[i][y-1]);
            else
                tmp = max(tmp, dfs(i, y-1, ans+1));
        }
        if(arr[i][y+1] > arr[x][y])
        {
            if(cut[i][y+1])
                tmp = max(tmp, ans + cut[i][y+1]);
            else
                tmp = max(tmp, dfs(i, y+1, ans+1));
        }
    }
    for(int i = x+2; i <= num; i++)
    {
        if(arr[i][y-1] > arr[x][y])
        {
            if(cut[i][y-1])
                tmp = max(tmp, ans + cut[i][y-1]);
            else
                tmp = max(tmp, dfs(i, y-1, ans+1));
        }
        if(arr[i][y+1] > arr[x][y])
        {
            if(cut[i][y+1])
                tmp = max(tmp, ans + cut[i][y+1]);
            else
                tmp = max(tmp, dfs(i, y+1, ans+1));
        }
    }
    for(int i = 1; i < y-1; i++)
    {
        if(arr[x-1][i] > arr[x][y])
        {
            if(cut[x-1][i])
                tmp = max(tmp, ans + cut[x-1][i]);
            else
                tmp = max(tmp, dfs(x-1, i, ans+1));
        }
        if(arr[x+1][i] > arr[x][y])
        {
            if(cut[x+1][i])
                tmp = max(tmp, ans + cut[x+1][i]);
            else
                tmp = max(tmp, dfs(x+1, i, ans+1));
        }
    }
    for(int i = y+2; i <= num; i++)
    {
        if(arr[x-1][i] > arr[x][y])
        {
            if(cut[x-1][i])
                tmp = max(tmp, ans + cut[x-1][i]);
            else
                tmp = max(tmp, dfs(x-1, i, ans+1));
        }
        if(arr[x+1][i] > arr[x][y])
        {
            if(cut[x+1][i])
                tmp = max(tmp, ans + cut[x+1][i]);
            else
                tmp = max(tmp, dfs(x+1, i, ans+1));
        }
    }
    cut[x][y] = tmp - ans + 1;
    return tmp;
}

int main()
{
    int r, c;
    while(scanf("%d", &num) != EOF)
    {
        memset(arr, 0, sizeof(arr));
        memset(cut, 0, sizeof(cut));
        scanf("%d%d", &r, &c);
        for(int i = 1; i <= num; i++)
            for(int j = 1; j <= num; j++)
                scanf("%d", &arr[i][j]);
        printf("%d\n", dfs(r, c, 1));
    }
    return 0;
}
