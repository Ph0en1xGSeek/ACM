#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int f;
    int b;
    double rat;
}arr[22];

int fron[3];
int bac[7];

bool cmp(const node& a, const node& b)
{
    if(a.rat == b.rat)
        return a.f < b.f;
    return a.rat < b.rat;
}

int main()
{
    int counts;
    while(scanf("%d", &fron[0]) != EOF)
    {
        counts = 0;
        scanf("%d%d", &fron[1], &fron[2]);
        for(int i = 0; i < 7; i++)
            scanf("%d", &bac[i]);
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 7; i++)
            {
                arr[counts].f = j+1;
                arr[counts].b = i+1;
                arr[counts++].rat = (fron[j] * 1.0)/(bac[i] * 1.0);
            }
        }
        sort(arr, arr+21, cmp);
        for(int i = 0; i < 21; i++)
            printf("%.2f %d %d\n", arr[i].rat, arr[i].f, arr[i].b);
    }
    return 0;
}
