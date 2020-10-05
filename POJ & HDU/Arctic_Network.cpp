#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
int father[502];
int part, num, m;

struct point
{
    double x;
    double y;
}p[505];

struct edge
{
    int from;
    int to;
    double w;
}e[250005];

int getFather(int n)
{
    if(father[n] == -1)
        return n;
    father[n] = getFather(father[n]);
    return father[n];
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

double kruskal(int j)
{
    int counts = 0;
    int x, y;
    double cost = 0;
    sort(e, e + j, cmp);
    for(int i = 0; i < j; i++)
    {
        x = getFather(e[i].from);
        y = getFather(e[i].to);
        if(x != y)
        {
            cost =max(cost, e[i].w);
            father[x] = y;
            counts++;
            if(counts == num - part)
                break;
        }
    }
    return cost;
}

int main()
{
    int ca;
    cin >> ca;
    while(ca--)
    {
        memset(father, -1, sizeof(father));
        m = 0;
        cin >> part >> num;
        for(int i = 0; i < num; i++)
        {
            cin >> p[i].x >> p[i].y;
            for(int j = 0; j < i; j++)
            {
                e[m].from = i;
                e[m].to = j;
                e[m].w = sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
                m++;
            }
        }
        cout << setprecision(2) << fixed << kruskal(m) << endl;;
    }
    return 0;
}
