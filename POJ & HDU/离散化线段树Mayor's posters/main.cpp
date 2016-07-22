#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 20010

using namespace std;

struct node
{
    int l, r, lazy;///懒操作，颜色若相同则记录该颜色，否则为0
}tree[M<<2];

struct Ending///端点
{
    int point;  ///离散化分配的坐标
    int num;    ///编号
}ending[M];

int arr[M][2];
int record[M];
int ans;

bool cmp(Ending a, Ending b)
{
    return a.point < b.point;
}

void build(int root, int l, int r)
{
//    cout << '#' << root << endl;
    tree[root].l = l;
    tree[root].r = r;
    tree[root].lazy = 0;
    if(l == r)  return;
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build((root << 1)|1, mid + 1, r);
}

void add(int root, int l, int r, int c)///l~r改成c
{
    if(tree[root].l == l && tree[root].r == r)
    {
        tree[root].lazy = c;
        return;
    }

    if(tree[root].lazy != 0)
    {
        tree[root<<1].lazy = tree[root].lazy;///懒操作补做
        tree[(root<<1)|1].lazy = tree[root].lazy;///但也只需要先改子节点的懒,以后再说
        tree[root].lazy = 0;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(l >= mid+1)
        add((root << 1)|1, l, r, c);
    else if(r <= mid)
        add(root << 1, l, r, c);
    else
    {
        add(root << 1, l, mid, c);
        add((root << 1)|1, mid+1, r, c);
    }
}

void findSum(int root)
{
    if(tree[root].lazy != 0)///下面颜色都相同，不用再往下
    {
        if(!record[tree[root].lazy])
        {
            ans++;
            record[tree[root].lazy] = 1;
        }
        return;
    }
    findSum(root<<1);
    findSum((root << 1)|1);
}

int main()
{
    int ca, num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%d%d", &arr[i][0], &arr[i][1]);
            ending[i<<1].point = arr[i][0];
            ending[(i<<1)|1].point = arr[i][1];
            ending[i<<1].num = -(i+1);///左节点标为负,+1防止0正负相同
            ending[(i<<1)|1].num = i+1;///右节点为正
        }

        ///离散化压缩区间
        sort(ending, ending + (num << 1), cmp);
        ///排序后把端点从小到大编号为1、2、3……
        int tmp = ending[0].point;
        int cnt = 1;
        for(int i = 0; i < (num << 1); i++)
        {
            if(ending[i].point != tmp)
            {
                cnt++;
                tmp = ending[i].point;
            }
            if(ending[i].num > 0)
                arr[ending[i].num-1][1] = cnt;
            else
                arr[-ending[i].num-1][0] = cnt;
        }
        build(1, 1, cnt);///区间建树
        for(int i = 0; i < num; i++)
            add(1, arr[i][0], arr[i][1], i+1);///区间上色
        memset(record, 0, sizeof(record));
        ans = 0;
        findSum(1);
        printf("%d\n", ans);

    }
    return 0;
}
