#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define M 500002

using namespace std;
int n, arr[M], c[M];
struct node
{
    int val;
    int order;
}nodes[M];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

void update(int t, int num)
{
    while(t <= n)
    {
        c[t] += num;
        t += (t & (-t));//lowbit
    }
}

int getsum(int t)
{
    int s = 0;
    while(t >= 1)
    {
        s += c[t];
        t -= (t & (-t));
    }
    return s;
}

int main()
{
    long long ans;
    while(scanf("%d", &n), n)
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &(nodes[i].val));
            nodes[i].order = i;
        }
        sort(nodes+1, nodes+n+1, cmp);
        for(int i = 1; i <= n; i++)
            arr[nodes[i].order] = i;
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            update(arr[i], 1);
            ans += i - getsum(arr[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
