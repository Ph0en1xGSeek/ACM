#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 0x7fffffff

using namespace std;

int ch[60010][2];///子节点编号，没有子节点指向根节点
int val[60010];
int num, cnt;
int s[1010];

void update(int v, int add)
{
    int tmp = 0;
    for(int i = 30; i >= 0; i--)
    {
        int c = (v >> i) & 1;
        if(!ch[tmp][c])
        {
            ch[cnt][0] = ch[cnt][1] = 0;
            val[cnt] = 0;
            ch[tmp][c] = cnt++;
        }
        tmp = ch[tmp][c];
        val[tmp] += add;
    }
}

int match(int v)
{
    int tmp = 0, ans = 0;
    for(int i = 30; i >= 0; i--)
    {
        int c = (v >> i) & 1;
        if(ch[tmp][c^1] != 0 && val[ch[tmp][c^1]])
        {
            ans |= (1 << i);
            tmp = ch[tmp][c^1];
        }
        else
            tmp = ch[tmp][c];
    }
    return ans;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        int num;
        scanf("%d", &num);
        cnt = 1;
        ch[0][0] = ch[0][1] = 0;
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &s[i]);
            update(s[i], 1);
        }
        int ans = -INF;
        for(int i = 1; i < num; i++)
        {
            update(s[i], -1);
            for(int j = i+1; j <= num; j++)
            {
                update(s[j], -1);
                int tmp = match(s[i]+s[j]);
                ans = max(ans, tmp);
                update(s[j], 1);
            }
            update(s[i], 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
