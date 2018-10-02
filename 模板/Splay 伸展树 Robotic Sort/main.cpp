#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 500006
#define INF 0x3f3f3f3f
#define lc (tr[id].c[0])
#define rc (tr[id].c[1])
#define KEY tr[tr[root].c[1]].c[0]


using namespace std;

int data[N/5];

struct Num
{
	int val, id;
	bool operator<(const Num a)const
	{
		if(val == a.val) return id < a.id;
		return val < a.val;
	}
}So[N/5];

struct Tr
{
	int fa, sum, val, c[2], lz; ///分别代表父节点，子树节点个数，节点的值，左右孩子以及懒标记
}tr[N];

int tot, root, n;

int newtr(int k, int f)///节点值，父节点，节点位置
{
	tr[tot].sum = 1;
	tr[tot].val = k;
	tr[tot].c[0] = tr[tot].c[1] = -1;
	tr[tot].lz = 0;
	tr[tot].fa = f;
	return tot++;
}

void Push(int id)	///更新suｍ值
{
	int lsum, rsum;
	lsum = (lc == -1)? 0:(tr[lc].sum);
	rsum = (rc == -1)? 0:(tr[rc].sum);
	tr[id].sum = lsum + rsum + 1;
}

int build(int l, int r, int f)
{
	if(l > r) return -1;
	int mid = (l+r)>>1;
	int ro = newtr(mid, f);///
	data[mid] = ro;
	tr[ro].c[0] = build(l, mid-1, ro);
	tr[ro].c[1] = build(mid+1, r, ro);
	Push(ro);
	return ro;
}

void lazy(int id)///区间翻转懒操作
{
	if(tr[id].lz)
	{
		swap(lc, rc);
		tr[lc].lz ^= 1, tr[rc].lz ^= 1;
		tr[id].lz = 0;
	}
}

void Rotate(int x, int k)
{
	if(tr[x].fa == -1) return;
	int fa = tr[x].fa, w;
    lazy(fa), lazy(x);
    tr[fa].c[!k] = tr[x].c[k];
    if(tr[x].c[k] != -1) tr[tr[x].c[k]].fa = fa;///x的孩子与fa关联
    tr[x].fa = tr[fa].fa, tr[x].c[k] = fa;///x与祖父以及父亲关联
    if(tr[fa].fa != -1)///祖父与x
    {
		w = tr[tr[fa].fa].c[1] == fa;
		tr[tr[fa].fa].c[w] = x;
    }
    tr[fa].fa = x;///fa与ｘ
    Push(fa);
    Push(x);
}

void Splay(int x, int goal)///把x旋转至goal下面
{
	if(x == -1) return;
	lazy(x);
	while(tr[x].fa != goal)
	{
		int y = tr[x].fa;
		lazy(tr[y].fa), lazy(y), lazy(x);
		bool w = (x == tr[y].c[1]);
		if(tr[y].fa != goal && w == (y == tr[tr[y].fa].c[1]))
			Rotate(y, !w);
		Rotate(x, !w);
	}

	if(goal == -1) root = x;
	Push(x);
}

int find(int k)///第k大
{
	int id = root;
	while(id != -1)
	{
		lazy(id);
		int lsum = (lc == -1)? 0:tr[lc].sum;
		if(lsum > k)
			id = lc;
		else if(lsum + 1 == k)
			break;
		else
		{
			k = k - lsum - 1;
			id = rc;
		}
	}
	return id;
}

int Getnext(int id)///在id右边的,根节点有效
{
	lazy(id);
	int p = tr[id].c[1];///右走一步
	if(p == -1) return id;
	lazy(p);
	while(tr[p].c[0] != -1)///左走到底
	{
		p = tr[p].c[0];
		lazy(p);
	}
	return p;
}

int main()
{
	int num;
	while(~scanf("%d", &num) && num != 0)
	{
		for(int i = 1; i <= num; i++)
		{
			scanf("%d", &So[i].val);
			So[i].id = i;
		}
		sort(So+1, So+num+1);
		So[0].id = 0;///前面加一个才表示第几个，否则是前面有几个
		int tot = 0;
		root = build(0, num+1, -1);///满足前后关系的splay树 左子树都在自己之前
		for(int i = 1; i <= num; i++)
		{
			int ro = data[So[i].id], nex;
			Splay(ro, -1);
			int d = tr[tr[root].c[0]].sum;
			int l = data[So[i-1].id];
			nex = Getnext(ro);///最后一个会返回自身
			Splay(l, -1);
			Splay(nex, root);
			lazy(root), lazy(tr[root].c[1]);
			tr[KEY].lz ^= 1;///排好序的后面 下一个序号之前的翻转 就是左右子树交换
			if(i != 1) printf(" ");
			printf("%d", d);
		}
		puts("");
	}
    return 0;
}
