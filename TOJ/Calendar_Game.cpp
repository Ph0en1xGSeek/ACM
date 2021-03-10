#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int f[2100][13][33];
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y)
{
    if(y%400==0||(y%100!=0&&y%4==0))return true;
    return false;
}

bool ok(int y,int m,int d)//看是不是合法的日期
{
    if(isleap(y)&&m==2)
    {
        if(d<=29)
            return true;
        else
            return false;
    }
    if(d<=days[m])
        return true;
    else
        return false;
}

int solve(int y,int m,int d)///当接手时日期为xxx是否必胜
{
    if(f[y][m][d] != -1)///-1为未标记
        return f[y][m][d];
    if(y==2001 && m == 11 && d == 4)
        return f[y][m][d] = 0;///必败为0
    if(y>2001)
        return f[y][m][d] = 1;///1为必胜
    else if(y == 2001 && m > 11)
        return f[y][m][d] = 1;
    else if(y==2001&&m==11&&d>4)
        return f[y][m][d] = 1;
    int ty,tm,td;
    ty = y;
    tm = m;
    td = d;
    if(isleap(y)&& m == 2)
    {
        td++;
        if(td==30)
        {
            tm=3;
            td=1;
        }
    }
    else
    {
        td++;
        if(td > days[tm])
        {
            td =  1;
            tm++;
            if(tm > 12)
                ty++,tm=1;
        }
    }
    if(solve(ty,tm,td)==0)
        return f[y][m][d] = 1;///找到一个必败态则为必胜态
    ty=y;
    tm=m;
    td=d;
    tm++;
    if(tm>12)
        ty++,tm=1;
    if(ok(ty,tm,td) && solve(ty,tm,td) == 0)
        return f[y][m][d] = 1;///找到一个必败态则为必胜态

    return f[y][m][d] = 0;///只能转到必胜态为必败态
}

int main()
{
    memset(f,-1,sizeof(f));
    int y,m,d;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d", &y, &m, &d);
        if(solve(y, m, d))
            printf("YES\n");///开始的为Adam必胜态1
        else
            printf("NO\n");
    }
    return 0;
}
