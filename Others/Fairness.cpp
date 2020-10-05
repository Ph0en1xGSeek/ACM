#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, ans;
bool flag;
int arr[105];

int abs(int x)
{
    if(x < 0)
        return -x;
    return x;
}

void dfs(int a, int b, int p)
{
    if(flag)
        return;
    if(p == n+1)
    {
        flag = true;
        return;
    }
    if(abs(a + arr[p] - b) <= ans)
        dfs(a + arr[p], b, p+1);
    if(abs(b + arr[p] - a) <= ans)
        dfs(a, b + arr[p], p+1);
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        int mi = 1, mx = 100;
        while(mi < mx)
        {
            int mid = (mi + mx) >> 1;
            flag = false;
            ans = mid;
            dfs(0,0,1);
            if(flag)
                mx = mid;
            else
                mi = mid + 1;
        }
        printf("%d\n", mx);
    }
    return 0;
}
