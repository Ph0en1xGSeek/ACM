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
    int cnt;///以该点为结尾的字符串个数
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
    tree[0].fail = -1;///根的fail指向-1（作为无法匹配的标记）
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
                if(tmp == 0)///与根相连的fail都指向根,类似于next[0] = -1
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
    int ans = 0, index, p = 0;///p为在树上与匹配串有最长公共前缀的位置
    for(int i = 0; str[i]; i++)///从第i位之前匹配
    {
        index = str[i] - 'a';
        while(tree[p].next[index] == 0 && p != 0)
            p = tree[p].fail;
        p = tree[p].next[index];
        int tmp = p;///tmp去找非最长公共前缀但也能匹配的串
        while(tmp != 0 && tree[tmp].cnt != -1)
        {
            ans += tree[tmp].cnt;
            tree[tmp].cnt = -1;///该串已经算上了 不能再算了
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
