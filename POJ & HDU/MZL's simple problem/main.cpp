#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

priority_queue<int> q;

int main()
{
    int ca, num, x;
    scanf("%d", &ca);
    int del;
    del = 0;
    while(!q.empty()) q.pop();
    while(ca--)
    {
        scanf("%d", &num);
        if(num == 1)
        {
            scanf("%d", &x);
            q.push(x);
        }
        else if(num == 2)
        {
            if(del < q.size())
                del++;
            if(del == q.size())
            {
                while(!q.empty())
                    q.pop();
                del = 0;
            }
        }
        else if(num == 3)
        {
            if(q.size() > del)
                printf("%d\n", q.top());
            else
                printf("0\n");
        }
    }
    return 0;
}
