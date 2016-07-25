#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#define MAXN 105
#define INF 1000000000
using namespace std;

struct node
{
    int pos;
    char x[12];
}tmp;

int top, found, st[400000], mi;
int d[] = {-1, -3, 1, 3};///左上右下
char as[] = "lurd";
bool mov[][4] = {{0,0,1,1}, {1,0,1,1}, {1,0,0,1}, {0,1,1,1}, {1,1,1,1}, {1,1,0,1}, {0,1,1,0}, {1,1,1,0}, {1,1,0,0}};///标记数组d能走的方式为1

int abs(int n)
{
    if(n < 0)
        return -n;
    else
        return n;
}

int h(node &t)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            int k = i * 3 + j;
            if(t.x[k] == 'x')
                continue;
            sum += abs(i - (t.x[k] - '1') / 3) + abs(j - (t.x[k] - '1') % 3);///3为行，%3为列
        }//该位置上的数距离原来该在的位置的曼哈顿距离
    return sum;
}

void output()
{
    for(int i = 1;i <= top; i++)
        printf("%c", as[st[i]]);
    printf("\n");
}

void dfs(int p, int dp, int maxdp)
{
    int f = h(tmp);
    int i, t;
    if(mi > f)
        mi = f;
    if(f + dp > maxdp || found)///若当前已走的dp布加至少要走的f步已经比最优解还差就剪枝
        return;
    if(f == 0)///找到
    {
        output();
        found = 1;
        return;
    }
    for(i = 0;i < 4; i++)
    {
        if(mov[p][i] == 0)///哪个方向能走就走过去
            continue;
        t = d[i] + p;
        if(top > 0 && d[st[top]] + d[i] == 0)
            continue;  ///一个重要的剪枝，如果之前的一步和现在的一步是相反的，不要回头。
        swap(tmp.x[t], tmp.x[p]);
        st[++top] = i;
        dfs(t, dp + 1, maxdp);
        top--;
        swap(tmp.x[t], tmp.x[p]);
    }
}

void IDA()
{
    int maxdp = h(tmp);///初始为初状态的h(x)值 初始深度限制
    found = 0;
    while(found == 0)
    {
        mi = 0x7fffffff; ///mi表示在当前的h值限制下所能搜到的最优位置，即h值最小的位置
        top = 0;
        dfs(tmp.pos, 0, maxdp);
        maxdp += mi; ///迭代加深IDA* 当前步数限制至少还需要mi步才能到，就加深mi
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        scanf("%s", &tmp.x[i]);
        if(tmp.x[i] == 'x')
            tmp.pos = i;
    }
    IDA();
    return 0;
}
