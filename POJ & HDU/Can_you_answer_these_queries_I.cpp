#include <iostream>
#include <stdio.h>

using namespace std;
int num[50005];

struct node
{
    int l;
    int r;
    int sum;//树所有数的和
    int ls, rs;///带有左右端点取的最大值
    int s;//此段可以取到的最大值
}tree[205000];

void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if(l == r)
    {
        tree[root].s = tree[root].sum = tree[root].ls = tree[root].rs = num[l];
        return;
    }

    int mid = (l + r)/2;
    build(2 * root, l, mid);
    build(2 * root + 1, mid + 1, r);
    tree[root].sum = tree[2 * root].sum + tree[2 * root + 1].sum;
    tree[root].s = max(tree[2 * root].rs + tree[2 * root + 1].ls, max(tree[2 * root].s, tree[2 * root + 1].s));
    tree[root].ls = max(tree[2 * root].ls, tree[2 * root].sum + tree[2 * root + 1].ls);
    ///带左端点的最大值等于左子树带左端点最大值 和 左子树所有和与右子树带左端点相加取大
    tree[root].rs = max(tree[2 * root + 1].rs, tree[2 * root + 1].sum + tree[2 * root].rs);
}

node findS(int root, int l, int r)
{
    if(tree[root].l == l && tree[root].r == r)
        return tree[root];
    int mid = (tree[root].l + tree[root].r)/2;
    if(mid >= r)
        return findS(2 * root, l, r);
    else if(mid < l)
        return findS(2 * root + 1, l, r);
    else
    {
        node a = findS(2 * root, l, mid);
        node b = findS(2 * root + 1, mid + 1, r);
        int most = max(a.rs + b.ls, max(b.s, a.s));
        node update;
        update.s = most;
        update.ls = max(a.sum + b.ls, a.ls);
        update.rs = max(b.rs, b.sum + a.rs);
        return update;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    int a, b;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        node ans = findS(1, a, b);
        printf("%d\n", ans.s);
    }


    return 0;
}
