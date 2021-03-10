#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>

using namespace std;
int n;
int c[32005];
int val[32005];//记录每个等级的数目

void update(int x, int num)
{
    while(x <= 32005)
    {
        c[x] += num;
        x += x&(-x);
    }
}

int getsum(int x)//前缀和，
{
    int ans = 0;
    while(x > 0)
    {
        ans += c[x];
        x -= x&(-x);
    }
    return ans;
}

int main()
{

    int x, y;
    while(scanf("%d", &n) != EOF)
    {
        memset(c, 0, sizeof(c));
        memset(val, 0, sizeof(val));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            x++; //防止 x=0 update时无限循环
            val[getsum(x)]++;
            update(x, 1);
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d\n", val[i]);
        }
    }

    return 0;
}
