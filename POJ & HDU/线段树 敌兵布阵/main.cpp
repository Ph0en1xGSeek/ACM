#include <iostream>
#include <stdio.h>
#include <cstring>
#define Max 50002

using namespace std;

int num[Max];
struct node
{
    int left;
    int right;
    int sum;
};
node tree[4*Max];

int build(int root, int left, int right)
{
    tree[root].left = left;
    tree[root].right = right;
    if(left == right)
        return tree[root].sum = num[left];
    int mid = (left + right) / 2;
    int a = build(2 * root, left, mid);
    int b = build(2 * root + 1, mid + 1, right);
    return tree[root].sum = a + b;
}

int findSum(int root, int left, int right)
{
    if(tree[root].left >= left && tree[root].right <= right)
        return tree[root].sum;
    if(right < tree[root].left || left > tree[root].right)
        return 0;
    int a = findSum(2 * root, left, right);
    int b = findSum(2 * root + 1, left, right);
    return a+b;
}

int add(int root, int pos, int val)
{
    if(pos == tree[root].right && pos == tree[root].left)
        return tree[root].sum = tree[root].sum + val;
    if(pos < tree[root].left || pos > tree[root].right)
        return tree[root].sum;
    int a = add(2 * root, pos, val);
    int b = add(2 * root + 1, pos, val);
    return tree[root].sum = a + b;
}

int main()
{
    int ca, n, counts = 1;
    int a, b;
    scanf("%d", &ca);
    char str[6];
    while(ca--)
    {
        scanf("%d", &n);
        printf("Case %d:\n", counts++);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
        }
        build(1, 1, n);
        while(~scanf("%s",str),str[0]!='E')
        {
            if(str[0]=='Q')
            {
                scanf("%d%d", &a, &b);
                cout << findSum(1, a, b) << endl;
            }
            else if(str[0]=='A')
            {
                scanf("%d%d", &a, &b);
                add(1, a, b);
            }
            else if(str[0]=='S')
            {
                scanf("%d%d", &a, &b);
                add(1, a, -b);
            }
        }
    }
    return 0;
}
