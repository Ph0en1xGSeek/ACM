#include <iostream>
#include <stdio.h>
#include <string.h>
#define M 1000010
#define N 100010

using namespace std;
int arr[N];
int cnt[M];
int ans[M];

int main()
{
    int num, mx;
    while(scanf("%d", &num) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(ans, 0, sizeof(ans));
        mx = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
            mx = max(mx, arr[i]);
        }
        for(int i = 1; i <= mx; i++)
            if(cnt[i])
            for(int j = i; j <= mx; j += i)
                ans[j] += cnt[i];
        for(int i = 0; i < num; i++)
        printf("%d\n", ans[arr[i]]-1);
    }

    return 0;
}
