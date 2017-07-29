#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int a, b;
}arr[1005];

bool cmp(node aa, node bb)
{
    if(aa.b == bb.b) return aa.a > bb.a;
    return aa.b > bb.b;
}

int main()
{
    int n;
    int ans;
    while(~scanf("%d", &n))
    {
        ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d%d", &arr[i].a, &arr[i].b);
        sort(arr, arr+n, cmp);
        int cnt = 1;
        for(int i = 0; i < n; i++)
        {
            if(cnt == 0) break;
            ans += arr[i].a;
            cnt += arr[i].b;
            cnt--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
