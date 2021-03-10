#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX 200
#define INF 999999

using namespace std;

int arr[MAX][MAX];
int main()
{
    int n, m, k;
    memset(arr, 0, sizeof(arr));
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        int mx = INF;
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            int tmp;
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &tmp);
                sum += tmp;
                arr[i][j] = sum;
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = i+1; j <= m; j++)
            {
                int sum = 0;
                int b = 0;
                for(int a = 1; a <= n; a++)
                {
                    sum += (arr[a][j] - arr[a][i]);
                    while(sum >= k && b < a)
                    {
                        mx = min(mx, (j-i)*(a-b));
                        b++;
                        sum -= (arr[b][j] - arr[b][i]);
                    }
                }
            }
        }

        if(mx != INF)
            printf("%d\n", mx);
        else
            printf("-1\n");
    }
    return 0;
}
