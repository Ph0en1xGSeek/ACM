#include <iostream>
#include <stdio.h>
#include <cstring>
#define M 50001
#define INF 10000000

using namespace std;

int arr[M];
int mi = INF, mx = 0;
struct node
{
    int l;
    int r;
    int mx;
    int mi;
}tree[3*M];

void build(int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if(l == r)
    {
        tree[root].mx = tree[root].mi = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
    tree[root].mi = min(tree[2*root].mi, tree[2*root+1].mi);
    tree[root].mx = max(tree[2*root].mx, tree[2*root+1].mx);
}

void query(int root, int l, int r)
{
    if(l <= tree[root].l && tree[root].r <= r)
    {
        mi = min(mi, tree[root].mi);
        mx = max(mx, tree[root].mx);
    }
    else if(tree[root].r < l || tree[root].l > r)
        return;
    else
    {
        query(2*root, l, r);
        query(2*root+1, l, r);
    }
}

int main()
{
    int n, q, a, b;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    build(1, 1, n);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d%d", &a, &b);
        mi = INF, mx = 0;
        query(1, a, b);
        printf("%d\n", mx-mi);
    }
    return 0;
}
