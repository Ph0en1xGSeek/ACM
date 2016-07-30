#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

char str[10010];
int vis[505];
int counts;

struct node
{
    int next[128];
    int fail;
    int cnt;///以该点为结尾的字符串编号
}tree[100010];

void add(int p)//字典树的插入
{
    int j = 0, index;
    for(int i = 0; str[i]; i++)
    {
        index = str[i];
        if(tree[j].next[index] == 0)
            tree[j].next[index] = ++counts;
        j = tree[j].next[index];
    }
    tree[j].cnt = p;
}

void ac_machine()//用bfs生成ac自动机，类似kmp中的getnext
{
    queue<int> q;
    tree[0].fail = -1;///根的fail指向-1（作为无法匹配的标记）
    q.push(0);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        int p;
        for(int i = 0; i < 128; i++)
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
        index = str[i];
        while(tree[p].next[index] == 0 && p != 0)
            p = tree[p].fail;
        p = tree[p].next[index];
        int tmp = p;///tmp去找非最长公共前缀但也能匹配的串
        while(tmp != 0)
        {
            if(tree[tmp].cnt)
            {
                ans++;
                vis[tree[tmp].cnt] = 1;
            }
            tmp = tree[tmp].fail;
        }
    }
    return ans;
}

int main()
{
    int num, cnt, num2;
    while(scanf("%d", &num) != EOF)
    {
        //memset(tree, 0, sizeof(tree));
        cnt = counts = 0;
        for(int i = 1; i <= num; i++)
        {
            scanf("%s", &str);
            add(i);
        }
        ac_machine();
        scanf("%d", &num2);
        for(int i = 1; i <= num2; i++)
        {
            memset(vis, 0, sizeof(vis));
            scanf("%s", &str);
            int tmp = query();
            if(tmp != 0)
            {
                cnt++;
                printf("web %d:", i);
                for(int j = 1; j <= num; j++)
                    if(vis[j]) printf(" %d", j);
                printf("\n");
            }
        }
        printf("total: %d\n", cnt);
    }
    return 0;
}
