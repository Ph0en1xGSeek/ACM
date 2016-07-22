#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<long long, vector<long long>, greater<long long> > q;
    long long num, n;
    long long tmp1, tmp2, ans;
    while(scanf("%lld", &num) != EOF)
    {
        ans = 0;
        for(long long i = 0; i < num; i++)
        {
            scanf("%lld", &n);
            q.push(n);
        }
        for(long long i = 1; i < num; i++)
        {
            tmp1 = q.top();
            q.pop();
            tmp2 = q.top();
            q.pop();
            ans += (tmp1 + tmp2);
            tmp1 += tmp2;
            q.push(tmp1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
