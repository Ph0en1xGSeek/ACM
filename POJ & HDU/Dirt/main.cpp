#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 1001

using namespace std;

int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int n, m, sx, sy, ex, ey;
int tp, tb;

struct node
{
    int curChange;
    int curStep;
    int x;
    int y;
    char c;
    friend bool operator<(const node a, const node b)
    {
        if(a.curChange == b.curChange)
            return a.curStep > b.curStep;
        return a.curChange > b.curChange;

    }
}arr[N][N];

bool isvalide(int x,int y)
{
    if(x<1 || x>n || y<1 ||y>m||arr[x][y].c=='0')
        return false;
    return true;
}

void BFS()
{
    int i,j,k;
    priority_queue<node> qu;
    node t1,t2;
    int tx,ty;
    arr[sx][sy].curStep=0;
    arr[sx][sy].curChange=0;
    t1=arr[sx][sy];
    t1.x=sx;
    t1.y=sy;
    qu.push(t1);
    while(!qu.empty())
    {
        t2=qu.top();
        if(t2.curChange>tb||(t2.curChange==tb&&t2.curStep>=tp))
            return;
        qu.pop();
        for(i=0;i<8;i++)
        {
            tx=t2.x+dir[i][0];
            ty=t2.y+dir[i][1];
            if(isvalide(tx,ty))
            {
                if(arr[tx][ty].curStep!=-1)
                {
                    if(arr[tx][ty].c!=t2.c)
                    {
                        if(arr[tx][ty].curChange<t2.curChange+1||(arr[tx][ty].curChange==t2.curChange+1&&arr[tx][ty].curStep<=t2.curStep+1))
                            continue;
                        arr[tx][ty].curChange=t2.curChange+1;
                        arr[tx][ty].curStep=t2.curStep+1;
                    }
                    else
                    {
                        if(arr[tx][ty].curChange<t2.curChange||(arr[tx][ty].curChange==t2.curChange&&arr[tx][ty].curStep<=t2.curStep+1))
                            continue;
                        arr[tx][ty].curChange=t2.curChange;
                        arr[tx][ty].curStep=t2.curStep+1;
                    }
                }
                else
                {
                    if(arr[tx][ty].c!=t2.c)
                    {
                        arr[tx][ty].curChange=t2.curChange+1;
                        arr[tx][ty].curStep=t2.curStep+1;
                    }
                    else
                    {
                        arr[tx][ty].curChange=t2.curChange;
                        arr[tx][ty].curStep=t2.curStep+1;
                    }
                }
                t1=arr[tx][ty];
                t1.x=tx;
                t1.y=ty;
                if(tx==ex&&ey==ty)
                {
                    if(t1.curChange<tb)
                    {
                        tb=t1.curChange;
                        tp=t1.curStep;
                    }
                    else if(t1.curChange==tb&&t1.curStep<tp)
                    {
                        tp=t1.curStep;
                    }
                    continue;
                }
                qu.push(t1);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n, &m))
    {
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        for(int i = 1; i <= n; i++)
        {
            getchar();
            for(int j = 1; j <= m; j++)
            {
                arr[i][j].c=getchar();
                arr[i][j].curStep=-1;
            }
        }
        tb=tp=100000;
        BFS();
        printf("%d %d\n",tp+1,tb);
    }
}
