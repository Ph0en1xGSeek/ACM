#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node
{
    int next[26];
    int cnt;//以这个点为前缀的词有几个
    node()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
}tree[20004];//0为root

char ch[1004][23];
int counts = 0, n = 0;

void add(int s)
{
    int j = 0;
    for(int i = 0; ch[s][i]; i++)
    {
        if(tree[j].next[ch[s][i] - 'a'] == 0)
            tree[j].next[ch[s][i] - 'a'] = ++counts;
        j = tree[j].next[ch[s][i] - 'a'];
        tree[j].cnt++;
    }
}

int search(int s)
{
    int i, j;
    for(i = 0, j = 0; ch[s][i]; i++)
    {
        j = tree[j].next[ch[s][i] - 'a'];
        if(tree[j].cnt == 1)
            return i;
    }
    return i-1;
}

int main()
{
    while(scanf("%s", ch[n]) != EOF)
        n++;
    for(int i = 0; i < n; i++)
        add(i);
    for(int i = 0; i < n; i++)
    {
        int j = search(i);
        printf("%s ", ch[i]);
        for(int k = 0; k <= j; k++)
            printf("%c", ch[i][k]);
        printf("\n");
    }
    return 0;
}
