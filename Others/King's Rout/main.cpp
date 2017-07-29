#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n,m,cnt;
int degree[200010];

struct node
{
  int to,next;

}edge[400005];

int head[200010];
void add(int a,int b)
{
    edge[cnt].to=b;
    edge[cnt].next=head[a];
    head[a]=cnt++;
}


priority_queue<int> q;
void topo(int x)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int y=edge[i].to;
        degree[y]--;
        if(!degree[y])
            q.push(y);
    }
}

int main()
{
    int i,j,k,a,b,ans[200005];

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0;
        k=0;
        while(!q.empty())
            q.pop();
        memset(degree,0,sizeof(degree));
        memset(head,-1,sizeof(head));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            degree[a]++;
            add(b,a);
        }
        for(i=1;i<=n;i++)
            if(degree[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int x=q.top();
            ans[k++]=x;
            q.pop();
            topo(x);
        }
        for(i=k-1;i>=0;i--)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
