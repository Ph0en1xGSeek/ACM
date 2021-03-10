#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node
{
    int next[2];
    int cnt;//以这个点为前缀的词有几个
    node()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
}tree[100];//0为root

char ch[10][10];
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
    int flag, ca = 1;
    n = 0;
    while(scanf("%s", ch[n++]) != EOF)
    {
        if(ch[n-1][0] == '9')
        {
            for(int i = 0; i < n-1; i++)
            {
                if(!add(i))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                printf("Set %d is immediately decodable\n", ca++);
            else
                printf("Set %d is not immediately decodable\n", ca++);

            for(int i = 0; i <= counts; i++)
            {
                memset(tree[i].next, 0, sizeof(tree[i].next));
                tree[i].cnt = 0;
            }
            flag = 1, counts = 0, n = 0;
        }

    }
    return 0;
}
