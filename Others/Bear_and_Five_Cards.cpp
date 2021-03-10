#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
map<int, int> m;

int main()
{
    int tot = 0;
    int sub = 0;
    int tmp;
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &tmp);
        if(m[tmp] == 0)
            q.push(tmp);
        m[tmp]++;
        tot += tmp;
    }
    while(!q.empty())
    {
        tmp = q.top();
        q.pop();
        if(m[tmp] >= 2)
        {
            int mul = min(3, m[tmp]);
            sub = max(sub, mul * tmp);
        }
    }
    int ans = tot - sub;
    printf("%d\n", ans);


    return 0;
}
