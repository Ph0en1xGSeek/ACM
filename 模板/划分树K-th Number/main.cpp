#include <iostream>
#include <stdio.h>
#include <algorithm>
#define Max 100010

using namespace std;
int val [20][Max], toLeft[20][Max];
int str[Max];
int m, n;

struct node
{
    int l;
    int r;
}tree[Max << 3];

void build(int root , int l, int r, int row)
{
    tree[root].l = l;
    tree[root].r = r;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    int emN = mid - l + 1;
    for(int i = l; i <= r; i++)
    {
        if(val[row][i] < str[mid])
            emN--;//一半以前与中位数相等的个数
    }
    int lp = l, rp = mid + 1;
    for(int i = l; i <= r; i++)
    {
        if(i == l)
            toLeft[row][i] = 0;
        else
            toLeft[row][i] = toLeft[row][i-1];//原串中前i个有几个放到了左边
        if(val[row][i] < str[mid])
        {
            val[row + 1][lp++] = val[row][i];//比中位数小的放在左边
            toLeft[row][i]++;
        }
        else if(val[row][i] > str[mid])
            val[row + 1][rp++] = val[row][i];//加右边
        else if(emN)//以下是相等的情况
        {
            val[row + 1][lp++] = val[row][i];
            toLeft[row][i]++;
            emN--;//当emN为0后 再相等也只能分到右边,保证两段等长
        }
        else
            val[row+1][rp++] = val[row][i];
    }
    build(2 * root + 1, l, mid, row + 1);
    build(2 * root + 2, mid + 1, r, row + 1);
}

int findK(int root, int l, int r, int k, int row)
{
    if(l == r)
        return val[row][l];
    int ll = l == tree[root].l ? 0 : toLeft[row][l-1];//在左子树找还是右子树找
    int lr = toLeft[row][r] - ll;
    if(k <= lr)
        return findK(2 * root + 1, tree[root].l + ll, tree[root].l + ll + lr - 1, k, row + 1);
    int mid = (tree[root].l + tree[root].r) >> 1;
    int rl = l - tree[root].l - ll;//总数-出现在左边的 = 出现在右边的
    int rr = r - l - lr + 1;
    return findK(2 * root + 2, mid + 1 + rl, mid + 1 + rl + rr -1, k - lr, row + 1);
}

int main()
{
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> str[i];
            val[0][i] = str[i];
        }
        sort(str, str + n);
        build(0, 0, n-1, 0);
        int a, b, c;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            cout << findK(0, a-1, b-1, c, 0) << endl;
        }

    }

    return 0;
}
