#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int dfs(int p, int q)
{
    if(p == q) return 1;
    if(p < q) return 2 * dfs(p, q-p);
    else    return 2 * dfs(p-q, q) + 1;
}

int main()
{
    int ca, c, p, q;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d %d/%d", &c, &p, &q);
        printf("%d %d\n", c, dfs(p, q));
    }
    return 0;
}
