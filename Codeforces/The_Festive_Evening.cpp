#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 1000006

using namespace std;

char str[M];
int cnt[M];

int main()
{
    int n, k;
    int ends[30][3];

    while(~scanf("%d%d", &n, &k))
    {
        memset(cnt, 0 ,sizeof(cnt));
        memset(ends, -1, sizeof(ends));
        scanf("%s", str);
        for(int i = 0; i < n; i++)
        {
            int tmp = str[i] - 'A';
            if(ends[tmp][0] == -1)
            {
                ends[tmp][0] = ends[tmp][1] = i;
            }
            else
                ends[tmp][1] = i;
        }
        for(int i = 0; i < 26; i++)
        {
            if(ends[i][0] == -1)
                continue;
            else
            {
                cnt[ends[i][0]]++;
                cnt[ends[i][1]+1]--;
            }
        }
        int ans = cnt[0];
        for(int i = 1 ; i <= n; i++)
        {
            cnt[i] += cnt[i-1];
            ans = max(ans, cnt[i]);
        }

        if(ans > k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
