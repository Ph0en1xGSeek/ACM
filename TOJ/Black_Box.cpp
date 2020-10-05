#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int> > q1;//´ó¶¥¶Ñ
    priority_queue<int, vector<int>, greater<int> > q2;

    int m, n, cnt;
    int add[30001], u;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        while(!q1.empty())  q1.pop();
        while(!q2.empty())  q2.pop();
        cnt = 0;
        for(int i = 0; i < m; i++)  scanf("%d", &add[i]);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &u);
            while(cnt < u)
            {
                q2.push(add[cnt++]);
                if(!q1.empty() && q2.top() < q1.top())
                {
                    int tmp = q2.top();
                    q2.pop();
                    q2.push(q1.top());
                    q1.pop();
                    q1.push(tmp);
                }
            }
            printf("%d\n", q2.top());
            q1.push(q2.top());
            q2.pop();
        }
    }
    return 0;
}
