#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[30];
int n, m;
int sum;

bool dfs(int x)
{
    if(sum == m)
        return true;
    if(x >= n)
        return false;
    sum += arr[x];
    if(dfs(x+1))
        return true;
    sum -= arr[x];
    if(dfs(x+1))
        return true;
    return false;
}

int main()
{
    while(~scanf("%d%d", &n, &m) && n != 0)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        if(dfs(0))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
