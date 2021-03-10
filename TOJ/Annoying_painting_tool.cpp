#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char arr[101][101];
    int n, m, r, c;
    bool flag;
    int cnt;
    int i, j;
    while(scanf("%d%d%d%d", &n, &m, &r, &c), n)
    {
        flag =  false;
        cnt = 0;
        for(i = 0; i < n; i++)
            scanf("%s", arr[i]);

        for(i = 0; i <= n-r && !flag; i++)
        {
            for(j = 0; j <= m-c; j++)
            {
                if(arr[i][j] == '1')
                {
                    cnt++;
                    for(int k = i; k < i+r; k++)
                        for(int t = j; t < j+c; t++)
                            arr[k][t] = (arr[k][t] == '0')? '1':'0';
                }
            }
            for(; j < m; j++)
                if(arr[i][j] == '1')
                {
                    flag = true;
                    break;
                }
        }
        for(; i < n && !flag; i++)
            for(int j = 0; j < m; j++)
                if(arr[i][j] == '1')
                {
                    flag = true;
                    break;
                }
        if(!flag)
            printf("%d\n", cnt);
        else
            printf("-1\n");
    }
    return 0;
}
