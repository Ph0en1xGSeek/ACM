#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> s;
int main()
{
    int ca, n;
    int ans;
    char str[105];
    scanf("%d", &ca);
    while(ca--)
    {
        while(!s.empty()) s.pop();
        ans = 0;
        scanf("%d", &n);
        scanf("%s", str);
        if(str[0] == ')')
        {
            ans++;
            str[0] = '(';
        }
        s.push(str[0]);
        for(int i = 1; i < n; i++)
        {
            if(s.empty())
            {
                if(str[i] == ')')
                {
                    ans++;
                    str[i] = '(';
                    s.push(str[i]);
                }
                else
                    s.push(str[i]);
            }
            else if(str[i] == '(')
                s.push(str[i]);
            else if(str[i] == ')')
                s.pop();
        }
        while(!s.empty())
        {
            ans++;
            s.pop();
            s.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}
