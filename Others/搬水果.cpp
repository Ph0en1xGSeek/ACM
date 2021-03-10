#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int t, num, n;
    int tmp1, tmp2, ans;
    while(scanf("%d", &num) && num != 0)
    {
        while(!q.empty()) q.pop();
        ans = 0;
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &n);
            q.push(n);
        }
        for(int i = 1; i < num; i++)
        {
            tmp1 = q.top();
            q.pop();
            tmp2 = q.top();
            q.pop();
            ans += (tmp1 + tmp2);
            tmp1 += tmp2;
            q.push(tmp1);
        }
        printf("%d\n", ans);
    }

    return 0;
}
