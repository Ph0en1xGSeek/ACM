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
    int cnt;///�Ըõ�Ϊ��β���ַ������
}tree[100010];

void add(int p)//�ֵ����Ĳ���
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

void ac_machine()//��bfs����ac�Զ���������kmp�е�getnext
{
    queue<int> q;
    tree[0].fail = -1;///����failָ��-1����Ϊ�޷�ƥ��ı�ǣ�
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
                if(tmp == 0)///���������fail��ָ���,������next[0] = -1
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
    int ans = 0, index, p = 0;///pΪ��������ƥ�䴮�������ǰ׺��λ��
    for(int i = 0; str[i]; i++)///�ӵ�iλ֮ǰƥ��
    {
        index = str[i];
        while(tree[p].next[index] == 0 && p != 0)
            p = tree[p].fail;
        p = tree[p].next[index];
        int tmp = p;///tmpȥ�ҷ������ǰ׺��Ҳ��ƥ��Ĵ�
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
