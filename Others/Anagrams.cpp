#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

queue<int> q;
stack<int> s;

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        while(!q.empty()) q.pop();
        while(!s.empty()) s.pop();
        num--;
        for(int i = 1; i*i <= num; i++)
        {
            if(num%i == 0)
            {
                if(i*i != num){
                    q.push(i);
                    s.push(num/i);
                }
                else{
                    q.push(i);
                }

            }
        }
        int tmp = q.front();
        q.pop();
        printf("%d", tmp);
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            printf(" %d", tmp);
        }
        while(!s.empty())
        {
            tmp = s.top();
            s.pop();
            printf(" %d", tmp);
        }
        printf("\n");
    }
    return 0;
}
