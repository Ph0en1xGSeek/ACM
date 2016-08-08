#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

struct node
{
    int next[26];
}tree[1000010];//0Ϊroot

string ch;
int counts = 0, n = 0;

int add()
{
    int i;
    int ans;
    int flag = 0;
    int j = 0;
    for(i = 0; ch[i]; i++)
    {
        if(tree[j].next[ch[i] - 'a'] == 0)
        {
            if(flag == 0)
            {
                ans = i+1;
                flag = 1;
            }
            tree[j].next[ch[i] - 'a'] = ++counts;
        }
        j = tree[j].next[ch[i] - 'a'];
        //tree[j].cnt++;
    }
    if(flag == 0)
        ans = i;
    return ans;
}

int main()
{
    int ca, num, ans;
    scanf("%d", &ca);
    for(int j = 1; j <= ca; j++)
    {
        ans = 0;
        memset(tree, 0, sizeof(tree));
        counts = 0;
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            cin >> ch;
            ans += add();
        }

        printf("Case #%d: %d\n", j, ans);
    }



    return 0;
}
