#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int pan[13];
int r, limit, flag;
int rotation[4][4] = {{0,1,4,3},{1,2,5,4},{3,4,7,6},{4,5,8,7}};

int h(int* b)//曼哈顿
{
    int ans = 0;
    for(int i = 0; i < 9; i++)
        ans += abs(i/3 - (b[i]-1)/3) + abs(i%3 - (b[i]-1)%3);
    return (ans+3)/4;
}

void change(int* b, int kind)
{
    if(kind&1)//顺时针
    {
        kind >>= 1;
        int tmp = b[rotation[kind][3]];
        for(int i = 3; i > 0; i--)
            b[rotation[kind][i]] = b[rotation[kind][i-1]];
        b[rotation[kind][0]] = tmp;
    }
    else
    {
        kind >>= 1;
        int tmp = b[rotation[kind][0]];
        for(int i = 0; i < 3; i++)
            b[rotation[kind][i]] = b[rotation[kind][i+1]];
        b[rotation[kind][3]] = tmp;
    }
}

void IDAstar(int* b, int deep, int pre)//矩阵，还能走，之前走法
{
    if(flag || h(b) > deep)
        return;
    if(deep == 0 && h(b) == 0)
    {
        flag = 1;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(pre != -1 && pre/2 == i/2 && (pre%2)^(i%2))
            continue;//相反步和第一步
        int tmp[9];
        for(int j = 0; j < 9; j++)
            tmp[j] = b[j];
        change(tmp, i);
        IDAstar(tmp, deep-1, i);
    }
}

int main()
{
    int ca = 1;
    char s[13];
    while(~scanf("%s", s) && strcmp(s, "0000000000"))
    {
        r = s[0] - '0';
        for(int i = 1; i <= 9; i++)
            pan[i-1] = s[i] - '0';
        flag = 0;
        for(limit = h(pan); limit <= r; limit++)
        {
            IDAstar(pan, limit, -1);
            if(flag)
            {
                printf("%d. %d\n", ca++, limit);
                break;
            }
        }

        if(!flag)
            printf("%d. -1\n", ca++);
    }
    return 0;
}
