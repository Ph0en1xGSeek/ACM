#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct interval
{
    long long l;
    long long r;
}it[50004];

bool cmp(interval a, interval b)
{
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
        scanf("%I64d%I64d", &it[i].l, &it[i].r);
    sort(it, it + num, cmp);
    long long x = it[0].l, y = it[0].r;
    for(int i = 1; i < num; i++)
    {
        if(y < it[i].l)
        {
            printf("%I64d %I64d\n", x, y);
            x = it[i].l, y = it[i].r;
        }
        else if(y < it[i].r)
            y = it[i].r;
    }
    printf("%I64d %I64d\n", x, y);
    return 0;
}
