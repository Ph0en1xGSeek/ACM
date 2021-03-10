#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> cow[2588], bottle[2588];
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int c, l;
    while(scanf("%d%d", &c, &l) != EOF)
    {
        for(int i = 0; i < c; i++)
            scanf("%d%d", &cow[i].first, &cow[i].second);
        for(int i = 0; i < l; i++)
            scanf("%d%d", &bottle[i].first, &bottle[i].second);
        sort(cow, cow+c);
        sort(bottle, bottle+l);
        int j = 0, ans = 0;
        for(int i = 0; i < l; i++)//ö�ٷ�ɹ˪
        {
            while(j < c && cow[j].first <= bottle[i].first)
            {
                q.push(cow[j].second);
                j++;
            }
            while(!q.empty() && bottle[i].second)
            {
                int tmp = q.top();
                q.pop();
                if(tmp >= bottle[i].first)
                {
                    ans++;
                    bottle[i].second--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
