#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define M 300
#define INF 0x7fffffff

using namespace std;

int arr[M][M];
bool visited[M];
int d[M];
int n, m;

void djikstra()
{
    memset(visited, 0, sizeof(visited));
    visited[1] = true;
    for(int i = 1; i <= n; i++)
        d[i] = arr[1][i];
    d[1] = 0;
    for(int i = 1; i < n; i++)///依次并入n-1个点
    {
        int mi = INF;
        int tmp;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && mi > d[j])
            {
                mi = d[j];
                tmp = j;
            }
        }
        if(tmp == n) return;
        visited[tmp] = true;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && arr[tmp][j] < INF && d[tmp] + arr[tmp][j] < d[j])
                d[j] = d[tmp] + arr[tmp][j] ;
        }
    }
}

int main()
{
    int a, b, c;
    while(scanf("%d%d", &n, &m) != EOF && n != 0)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                arr[i][j] = INF;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            arr[a][b] = arr[b][a] = c;
        }
        djikstra();
        printf("%d\n", d[n]);
    }
    return 0;
}
