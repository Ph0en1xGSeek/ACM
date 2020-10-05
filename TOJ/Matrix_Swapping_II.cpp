#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

bool cmp(int a, int b)
{
    return a> b;
}

int main()
{
    int num[1005], tmp[1005];
    int n, m, ans;
    char t;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        ans = 0;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++)
        {
            getchar();
            for(int j = 1; j <= m; j++)
            {
                t = getchar();
                if(t == '1')   num[j]++;
                else    num[j] = 0;
                tmp[j] = num[j];
            }
            sort(tmp+1, tmp + m +1, cmp);
            for(int j = 1; j <= m && tmp[j]; j++)
            {
                if(tmp[j]*j > ans)
                    ans = tmp[j]*j;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
