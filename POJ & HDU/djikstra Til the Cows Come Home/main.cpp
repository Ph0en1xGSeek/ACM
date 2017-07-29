#include <iostream>
#define INF 1<<29

using namespace std;
int t, n;
int a, b, len;
int arr[1005][1005];

void djikstra()
{
    bool isVisted[1005];
    int d[1005];
    int min, tmp;
    for(int i =1; i <= n; i++)
    {
        isVisted[i] = 0;
        d[i] = arr[1][i];
    }
    for(int i = 1; i <= n; i++)//从1点开始要并入n个点
    {
        min = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!isVisted[j] && d[j] < min)//找到距离原点最近且没走过的点
            {
                tmp = j;
                min = d[j];
            }
        }
        isVisted[tmp] = 1;

        for(int j = 1; j <= n; j++)//更新离原点的距离 无联系的暂不更新
            if(!isVisted[j] && d[j] > arr[tmp][j] + d[tmp])
                d[j] = arr[tmp][j] + d[tmp];
    }
    cout << d[n] << endl;
}


int main()
{
    cin >> t >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i==j)
                arr[i][i] = 0;
            else
                arr[i][j] = arr[j][i] = INF;
        }
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> len;
        if(arr[a][b] > len)
            arr[a][b] = arr[b][a] = len;
    }
    djikstra();
    return 0;
}
