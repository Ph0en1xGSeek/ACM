#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
    int c;
    int t;
    bool operator<(const node & n) const
    {
        return c < n.c;
    }
}tmp;

priority_queue<node> q;
node ans[300010];
int pos[300010];

int main()
{
    int n, k;
    while(~scanf("%d%d", &n ,&k))
    {
        while(!q.empty()) q.pop();
        int t = min(k+1, n);
        for(int i = 1; i <= t; i++)
        {
            scanf("%d", &tmp.c);
            tmp.t = i;
            q.push(tmp);
        }
        for(int i = 0; i < n; i++)
        {
            tmp = q.top();
            q.pop();
            ans[i] = tmp;
            if(i < n-t)
            {
                scanf("%d", &tmp.c);
                tmp.t = i+k+2;
                q.push(tmp);
            }
        }
        long long result = 0;
        for(int i = 0; i < n; i++)
        {
            result += (long long)(k+1+i - ans[i].t) * (long long)ans[i].c;
            pos[ans[i].t-1] = k+1+i;
        }
        printf("%I64d\n", result);
        for(int i = 0; i < n; i++)
            printf("%d ", pos[i]);
        printf("\n");
    }
    return 0;
}
