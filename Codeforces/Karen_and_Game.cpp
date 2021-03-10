#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 105
#define INF 100000000

using namespace std;

int arr[M][M];

int main() {
    int n, m;
    int cntRow[M];
    int cntCol[M];
    int mi;
    bool flag;
    int sum;

    while (~scanf("%d%d", &n, &m))
    {
        flag = true;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        if(n <= m)
        {
            for(int i = 0; i < n; i++)
            {
                mi = INF;
                for(int j = 0; j < m; j++)
                {
                    if(arr[i][j] < mi)
                        mi = arr[i][j];
                }
                cntRow[i] = mi;
                sum += mi;
                for(int j = 0; j < m; j++)
                    arr[i][j] -= mi;
            }

            for(int j = 0; j < m && flag; j++)
            {
                cntCol[j] = arr[0][j];
                sum += cntCol[j];
                for(int i = 1; i < n; i++)
                {
                    if(arr[i][j] != cntCol[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        else
        {
            for(int j = 0; j < m; j++)
            {
                mi = INF;
                for(int i = 0; i < n; i++)
                {
                    if(arr[i][j] < mi)
                        mi = arr[i][j];
                }
                cntCol[j] = mi;
                sum += mi;
                for(int i = 0; i < n; i++)
                    arr[i][j] -= mi;
            }

            for(int i = 0; i < n && flag; i++)
            {
                cntRow[i] = arr[i][0];
                sum += cntRow[i];
                for(int j = 1; j < m; j++)
                {
                    if(arr[i][j] != cntRow[i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if(!flag)   printf("-1\n");
        else
        {
            printf("%d\n", sum);
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < cntRow[i]; j++)
                    printf("row %d\n", i+1);
            }

            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < cntCol[i]; j++)
                    printf("col %d\n", i+1);
            }
        }
    }
    return 0;
}