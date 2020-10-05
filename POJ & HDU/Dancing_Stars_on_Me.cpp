#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> p[105];
vector<int> v;

int main()
{
    int ca, num, a, b;
    scanf("%d", &ca);
    bool flag = 1;
    while(ca--)
    {
        flag = 1;
        v.clear();
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
            scanf("%d%d", &p[i].first, &p[i].second);
        if(num != 4)
        {
            printf("NO\n");
            continue;
        }
        sort(p, p+num);
        for(int i = 0; i < 3; i++)
            for(int j = i+1; j < 4; j++)
            {
                int tmp = (p[j].first - p[i].first)*(p[j].first - p[i].first) + (p[j].second - p[i].second)*(p[j].second - p[i].second);
                v.push_back(tmp);
            }
        sort(v.begin(), v.end());
        for(int i = 0; i < 3; i++)
            if(v[i] != v[i+1])
                flag = false;
        if(v[3] == v[4]) flag = false;
        if(v[4] != v[5]) flag = false;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
