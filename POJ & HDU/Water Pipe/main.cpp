#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int sx, sy, ex, ey, n;
int hx[1005], hy[1005];///����ÿ��x��y������Ҫ����ˮ��
int sum, ans;///ansΪ������ƣ�Ҳ�����Ĵ�
struct node
{
    int l,c;
}a[10];

void bfs(int *h, int pos)//�����п��ܵ���ĵ�
{
    int i;
    queue<int> Q;
    h[pos] = 0;//�ﵽ�յ����ٲ���
    Q.push(pos);
    while(!Q.empty())
    {
        pos = Q.front();
        Q.pop();
        for(i = 0; i < n; i++)
        {
            if(pos-a[i].l >= 1 && h[pos - a[i].l] == -1)
            {
                h[pos-a[i].l] = h[pos]+1;
                Q.push(pos-a[i].l);
            }
            if(pos+a[i].l<=1000 && h[pos+a[i].l]==-1)
            {
                h[pos+a[i].l] = h[pos]+1;
                Q.push(pos+a[i].l);
            }
        }
    }
}

int IDA(node *a, int x, int deep, int kind)///kind 0Ϊ�� 1Ϊ��
{
    int i,hv;
    node tem[10];
    hv = kind? hy[x] : hx[x];
    if(hv == -1 || hv + deep > ans)
        return 0;
    if(hv == 0)///���ҵ�����
    {
        if(kind == 0) return IDA(a,sy,deep,1);
        else return 1;
    }
    for(i = 0; i < n; i++)
        tem[i] = a[i];
    for(i = 0; i<n; i++)
    {
        if(tem[i].c <= 0)
            continue;
        tem[i].c--;
        if(x-tem[i].l >= 1)
            if(IDA(tem, x-tem[i].l, deep+1, kind))
                return 1;
        if(x+tem[i].l <= 1000)
            if(IDA(tem, x+tem[i].l, deep+1, kind))
                return 1;
        tem[i].c++;
    }
    return 0;
}

void solve()
{
    memset(hx, -1, sizeof(hx));
    memset(hy, -1, sizeof(hy));
    bfs(hx, ex);
    bfs(hy, ey);
    for(ans = 1; ans <= sum; ans++)
        if(IDA(a, sx, 0, 0))
            break;
    if(ans <= sum)
        printf("%d\n",ans);
    else
        printf("-1\n");
}

int main()
{
    sum = 0;
    scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i].l);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].c);
        sum += a[i].c;
    }
    if(sx == ex && sy == ey)
        printf("0\n");
    else
        solve();

    return 0;
}
