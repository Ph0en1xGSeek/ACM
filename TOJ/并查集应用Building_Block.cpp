#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 333333

using namespace std;

int father[M];
int num[M];///每堆有多少
int under[M];

int getFather(int x)
{
    if(father[x] == -1)
        return x;
    int tmp = getFather(father[x]);
    under[x] += under[father[x]];///每次getfather时才会计算出现在下面有多少
    return (father[x] = tmp);
}

void unions(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);
    if(fa != fb)
    {
        under[fa] = num[fb];///a所在堆的最底下一块下面为b堆个数，树根的under为0
        ///注意a之上的还没有更新，仍然是之前的数，直到getFather时才会更新
        ///递归把父节点的under加上
        num[fb] += num[fa];///b所在堆个数加上a所在堆
        father[fa] = fb;///再查询a就会查询到b这一堆
    }
}

int main()
{
    int p, a, b;
    char ch;
    while(scanf("%d", &p) != EOF)
    {
        memset(father, -1, sizeof(father));
        for(int i = 0; i <= 300000; i++)
            num[i] = 1;
        memset(under, 0, sizeof(under));
        for(int i = 0; i < p; i++)
        {
            getchar();
            scanf("%c", &ch);
            if(ch == 'M')
            {
                scanf("%d%d", &a, &b);
                unions(a, b);
            }
            else
            {
                scanf("%d", &a);
                getFather(a);
                printf("%d\n", under[a]);
            }
        }
    }
    return 0;
}
