#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int x, y;
    bool operator<(const node &a) const
    {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
}p[35];

struct rectangle
{
    node p1, p2;
    int area;
}r[1000];

bool mp[204][204];

int check(int i, int j)
{
    if(r[i].p2.x < r[j].p1.x) return 1;
    if(r[i].p2.y < r[j].p1.y) return 1;
    if(r[i].p1.y > r[j].p2.y) return 1;
    if(r[i].p1.x < r[j].p1.x && r[i].p1.y < r[j].p1.y && r[i].p2.y > r[j].p2.y && r[i].p2.x > r[j].p2.x)
        return 2;
    return 0;
}

int main()
{
    int cnt, ans;
    int num;
    while(~scanf("%d", &num) && num != 0)
    {
        memset(mp, false, sizeof(mp));
        for(int i = 0; i < num; i++)
        {
            scanf("%d %d", &p[i].x, &p[i].y);
            mp[p[i].x][p[i].y] = true;
        }
        sort(p, p+num);
        cnt = 0;
        for(int i = 0; i < num-1; i++)
            for(int j = i+1; j < num; j++)
                if(p[i].x < p[j].x && p[i].y < p[j].y && mp[p[i].x][p[j].y] && mp[p[j].x][p[i].y])
                {
                    r[cnt].p1.x = p[i].x;
                    r[cnt].p1.y = p[i].y;
                    r[cnt].p2.x = p[j].x;
                    r[cnt].p2.y = p[j].y;
                    r[cnt++].area = (p[j].x-p[i].x)*(p[j].y-p[i].y);
                }
        ans = -1;
        for(int i = 0; i < cnt-1; i++)
            for(int j = i+1; j < cnt; j++)
            {
                int tmp = check(i, j);
                if(tmp == 1)
                    ans = max(ans, r[i].area+r[j].area);
                else if(tmp == 2)
                    ans = max(ans, r[i].area);
            }
        if(ans == -1)
            printf("imp\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
