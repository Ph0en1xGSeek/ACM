#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define MAX 1000005
#include <queue>

using namespace std;

struct node
{
    long long base;
    long long seg;
    bool operator<(const node &b) const
    {
        return seg > b.seg;
    }
};

long long w[MAX], d[MAX], time[MAX];
int main()
{
    int ca, l, n, m;
    node tmp1;
    scanf("%d", &ca);
    for(int j = 1; j <= ca; j++)
    {
        priority_queue<node> q1, q2;
        scanf("%d%d%d", &l, &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%lld", &w[i]);
        for(int i = 0; i < m; i++)
            scanf("%lld", &d[i]);
        for(int i = 0; i < n; i++)
        {
            tmp1.base = w[i];
            tmp1.seg = w[i];
            q1.push(tmp1);
        }
        for(int i = 0; i < m; i++)
        {
            tmp1.base = d[i];
            tmp1.seg = d[i];
            q2.push(tmp1);
        }
        for(int i = 0; i < l; i++)
        {
            tmp1 = q1.top();
            q1.pop();
            ///第i个的结束时间
            time[i] = tmp1.seg;
            tmp1.seg += tmp1.base;
            q1.push(tmp1);
        }
        long long ans = 0;
        ///烘干过程倒着走和洗衣服过程一样
        ///从最晚结束洗衣开始，就是最早倒着完成烘干
        for(int i = l-1; i >= 0; i--)
        {
            tmp1 = q2.top();
            q2.pop();
            ans = max(ans, time[i] + tmp1.seg);
            tmp1.seg += tmp1.base;
            q2.push(tmp1);
        }
        printf("Case #%d: %lld\n", j, ans);

    }
    return 0;
}
