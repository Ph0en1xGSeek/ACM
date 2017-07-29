#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

int cnt, arr[100000];

int solve()
{
    stack<int> s, sum;//实际空间 剩余空间
    for(int i = 0; i < cnt; i++)
    {
        if(arr[i] < 0)
        {
            if(s.size() > 0)
            {
                if(sum.top() <= abs(arr[i]))
                    return 0;
                int tmp = sum.top();
                tmp -= abs(arr[i]);
                sum.pop();
                sum.push(tmp);
            }
            s.push(arr[i]);
            sum.push(abs(arr[i]));
        }
        else
        {
            if(s.empty() || -(s.top()) != arr[i])
                return 0;
            s.pop();
            sum.pop();
        }
    }
    return 1;
}

int main()
{
    cnt = 0;
    int b, flag;
    char c;
    while(scanf("%d%c", &b, &c) != EOF)
    {
        arr[cnt++] = b;
        if(c == '\n')
        {
            if(cnt % 2)
                printf(":-( Try again.\n");
            else
            {
                flag = solve();
                if(flag)
                    printf(":-) Matrioshka!\n");
                else
                    printf(":-( Try again.\n");
            }
            cnt = 0;
        }
    }
    return 0;
}
