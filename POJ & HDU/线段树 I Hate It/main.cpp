#include <stdio.h>
#include <iostream>
#define Max 200005

using namespace std;
struct node
{
    int l;
    int r;
    int mx;
};
int num[Max];
node tree[Max * 20];
int n, m;

int build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if(l == r)
        return tree[root].mx = num[l];
    int mid;
    mid = (l + r) / 2;
    int a, b;
    a = build(2 * root, l, mid);
    b = build(2 * root + 1, mid + 1, r);
    return tree[root].mx = max(a, b);
}

int findMx(int root, int l, int r)//找区间的最大值
{
    if(tree[root].l > r || tree[root].r < l)
        return 0;
    if(l <= tree[root].l && r >= tree[root].r)//只算包在区间内的2
        return tree[root].mx;
    int a,b;
    a = findMx(2 * root, l, r);
    b = findMx(2 * root + 1, l, r);
    return max(a, b);
}

int update(int root, int pos, int val)
{
    if(pos < tree[root].l || pos > tree[root].r)
        return tree[root].mx;
    if(tree[root].l == pos && tree[root].r == pos)
        return tree[root].mx = val;
    int a = update(2 * root, pos, val);
    int b = update(2 * root + 1, pos, val);

    tree[root].mx = max(a, b);
    return tree[root].mx;
}

int main()
{
    char ch;
    int a, b;
    while(scanf ("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        build(1, 1, n);
        for(int i = 0; i < m; i++)
        {
            getchar();
            scanf("%c%d%d", &ch, &a, &b);
            if(ch == 'Q')
                printf("%d\n", findMx(1, a, b));
            else
            {
                num[a] = b;
                update(1, a, b);
            }
        }
    }
    return 0;
}
