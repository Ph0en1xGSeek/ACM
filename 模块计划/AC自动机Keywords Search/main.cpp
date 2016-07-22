#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char str[1000010];
int counts;
queue<int> q;

struct node
{
    int next[26];
    int fail;
    int cnt;//以改点为结尾的字符串个数
}tree[500001];

void add()//字典树的插入
{
    int j = 0, index;
    for(int i = 0; str[i]; i++)
    {
        index = str[i] - 'a';
        if(tree[j].next[index] == 0)
            tree[j].next[index] = ++counts;
        j = tree[j].next[index];
    }
    tree[j].cnt++;
}

void ac_machine()//用bfs生成ac自动机，类似kmp中的getnext
{
    tree[0].fail = -1;
    q.push(0);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        int p;
        for(int i = 0; i < 26; i++)
        {
            if(tree[tmp].next[i] != 0)
            {
                if(tmp == 0)//与根相连的fail都指向根
                    tree[tree[tmp].next[i]].fail = 0;
                else
                {
                    p = tree[tmp].fail;
                    while(p != -1)
                    {
                        if(tree[p].next[i] != 0)
                        {
                            tree[tree[tmp].next[i]].fail = tree[p].next[i];
                            break;
                        }
                        p = tree[p].fail;
                    }
                    if(p == -1)
                        tree[tree[tmp].next[i]].fail = 0;
                }
                q.push(tree[tmp].next[i]);
            }
        }
    }
}

int query()
{
    int ans = 0, index, p = 0;
    for(int i = 0; str[i]; i++)
    {
        index = str[i] - 'a';
        while(tree[p].next[index] == 0 && p != 0)
            p = tree[p].fail;
        p = tree[p].next[index];
        int tmp = p;
        while(tmp != 0 && tree[tmp].cnt != -1)
        {
            ans += tree[tmp].cnt;
            tree[tmp].cnt = -1;
            tmp = tree[tmp].fail;
        }
    }
    return ans;
}

int main()
{
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(tree, 0, sizeof(tree));
        counts = 0;
        while(!q.empty())
            q.pop();
        scanf("%d", &num);
        while(num--)
        {
            scanf("%s", str);
            add();
        }
        ac_machine();
        scanf("%s", str);
        printf("%d\n", query());
    }
    return 0;
}
