#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char arr[55][55];
int cnt[4];

int main()
{
    int n, m;
    int ans, flag;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", arr[i]);
        }

        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < m-1; j++)
            {
                memset(cnt, 0, sizeof(cnt));
                for(int a = 0; a < 2; a++)
                    for(int b = 0; b < 2; b++)
                    {
                        if(arr[i+a][j+b] == 'a')
                            cnt[0]++;
                        else if(arr[i+a][j+b] == 'c')
                            cnt[1]++;
                        else if(arr[i+a][j+b] == 'e')
                            cnt[2]++;
                        else if(arr[i+a][j+b] == 'f')
                            cnt[3]++;
                    }

                flag = 1;
                for(int k = 0; k < 4; k++)
                    if(cnt[k] == 0)
                        flag = 0;
                if(flag == 1)
                    ans++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
