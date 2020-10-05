#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 2000

using namespace std;

int n;
char str[M];
int num[26][M];
int ans[26][M];
int q, m;
char ch;

int main()
{
    while(~scanf("%d", &n))
    {
        scanf("%s", &str[1]);
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++)
        {
            int tmp = str[i] - 'a';
            for(int j = 0; j < 26; j++)
            {
                if(j == tmp)
                    num[j][i] = num[j][i-1];
                else
                    num[j][i] = num[j][i-1] + 1;
            }
        }

        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < 26; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int tot = 0;
                int right = 1;
                for(int k = 1; k <= n; k++)
                {
                    while(right < n && num[i][right+1] - num[i][k-1] <= j)
                        right++;
                    tot = max(tot, right - k + 1);
                }
                ans[i][j] = tot;
            }
        }

        scanf("%d", &q);

        for(int i = 0; i < q; i++)
        {
            scanf("%d", &m);
            getchar();
            scanf("%c", &ch);
            printf("%d\n", ans[ch-'a'][m]);
        }

    }
    return 0;
}
