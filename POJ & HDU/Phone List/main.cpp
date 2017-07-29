#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node
{
    int next[10];
    int cnt;//以这个点为前缀的词有几个
    node()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
}tree[100004];//0为root

char ch[10001][10];
int counts = 0, n;

bool add(int s)
{
    bool f1 = true, f2 = false;//没覆盖别人，没被人覆盖
    int j = 0;
    for(int i = 0; ch[s][i]; i++)
    {
        if(tree[j].next[ch[s][i] - '0'] == 0)
        {

            f2 = true;
            tree[j].next[ch[s][i] - '0'] = ++counts;
        }
        if(tree[j].cnt == 1)
            f1 = false;
        j = tree[j].next[ch[s][i] - '0'];
    }
    tree[j].cnt = 1;
    return (f1 && f2);
}

int main()
{
    int ca, flag;
    scanf("%d", &ca);
    while(ca--)
    {
        for(int i = 0; i <= counts; i++)
        {
            memset(tree[i].next, 0, sizeof(tree[i].next));
            tree[i].cnt = 0;
        }
        flag = 1, counts = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", ch[i]);
            if(!flag);
            else if(!add(i))
                flag = 0;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
