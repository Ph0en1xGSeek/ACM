#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct seg
{
    int x, y;
    bool operator<(const seg& a) const
    {
        return x < a.x;
    }
}arr[1010];
int n, r;

int yArr[1010];
int top;

void getY(int x)
{
    top = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].x >= x && arr[i].x <= x+r)
          yArr[top++] = arr[i].y;
    }
    sort(yArr, yArr + top);
}

int solve()
{
    int low = 0, tmp, mx = 0;
    for(int i = 1; i < top; i++)
    {
        while(yArr[i] - yArr[low] > r) low++;
        tmp = i - low + 1;
        mx = max(mx, tmp);
    }
    return mx;
}

int main()
{
    int ans;
    while(~scanf("%d%d", &n, &r))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr+n);
        int tmp = -1, t;
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].x == tmp) continue;
            tmp = arr[i].x;
            getY(tmp);
            t = solve();
            ans = max(ans, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
