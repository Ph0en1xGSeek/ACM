#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dfs(int n, int k)
{
    if(n == k) return k;
    int x = dfs(n-n/k, k);
    return (x-1) / (k-1) + x;
}

int main()
{
    int ca;
    int n, k;
    while(~scanf("%d", &ca))
    {
        while(ca--)
        {
            scanf("%d%d", &n, &k);
            int ans = dfs(n, k);
            printf("%d\n", ans);
        }
    }
    return 0;
}
