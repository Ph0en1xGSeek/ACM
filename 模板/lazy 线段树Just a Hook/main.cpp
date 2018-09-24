#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int l,r,num,lazy;
}Tree;

Tree tree[500005];

void Build(int root,int l,int r)
{
    int mid;
    tree[root].l = l;
    tree[root].r = r;
    tree[root].num = r-l+1;///��ʼ��Ϊ1
    tree[root].lazy = 1;///�ӽڵ㶼һ��������־Ϊ1
    if (l==r) return;
    mid=(l+r)/2;
    Build(2 * root + 1, l, mid);
    Build(2 * root + 2, mid+1, r);
}

void Add(int root,int x,int y,int c)
{
    int mid,l,r;
    l=tree[root].l;
    r=tree[root].r;
    if (l==x && r==y)
    {
        tree[root].lazy=1;
        tree[root].num=(r-l+1)*c;//�����������һƬ��һ�����ȱ�Ϳɫ��ֻҪ����ܼ�ֵ�Ϳ�����
        return;
    }
    mid=(l+r)/2;
    if (tree[root].lazy==1)///��֮ǰ͵����
    {
        tree[root].lazy=0;//�����ֱ��ģ�������ɫ��һ
        Add(2*root+1, l, mid, tree[root].num/(r-l+1));
        Add(2*root+2, mid+1, r, tree[root].num/(r-l+1));
    }
    if (x<=mid) Add(2 * root + 1, x, min(mid,y), c);///��Ҫ������
    if (y>mid) Add(2 * root + 2, max(mid+1,x), y, c);///��Ҫ���Һ���
    tree[root].num=tree[2*root+1].num+tree[2*root+2].num;
}

int Find(int t)
{
    return tree[0].num;
    //if (tree[t].lazy==1) return tree[t].num;
    //return Find(2*t+1)+Find(2*t+2);
}

int main()
{
    int i,j,n,T,m,x,y,c,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        Build(0,0,n-1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&c);
            Add(0,x-1,y-1,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",cnt++,Find(0));
    }
    return 0;
}
