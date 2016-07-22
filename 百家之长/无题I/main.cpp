#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,t;
int map[17];
int counts(int* mid,int a,int b,int c,int d)
{
    int cnt[5]={0,0,0,0,0};
    cnt[mid[a]]++,cnt[mid[b]]++,cnt[mid[c]]++,cnt[mid[d]]++;
    return max(max(cnt[1],cnt[2]),max(cnt[3],cnt[4]));
}
int counts(int* mid)//最少要多少步
{
    int maxf=0,maxt=0;
    maxf = max(maxf,max(4-counts(mid,1,2,3,4),4-counts(mid,5,6,7,8)));
    maxf = max(maxf,max(4-counts(mid,9,10,11,12),4-counts(mid,13,14,15,16)));
    maxt = max(maxt,max(4-counts(mid,1,5,9,13),4-counts(mid,2,6,10,14)));
    maxt = max(maxt,max(4-counts(mid,3,7,11,15),4-counts(mid,4,8,12,16)));
    return min(maxf,maxt);
}
bool isok(int now,int f)//反向剪枝
{
    if(f==-1) return 1;
    if(f+now==17) return 0;
    return 1;
}
void swap(int* mid,int a,int b,int c,int d)
{
    int pt=mid[a];
    mid[a]=mid[b],mid[b]=mid[c],mid[c]=mid[d];
    mid[d]=pt;
}
void swap(int* mid,int id)
{
    if(id==1) swap(mid,1,2,3,4);
    if(id==2) swap(mid,5,6,7,8);
    if(id==3) swap(mid,9,10,11,12);
    if(id==4) swap(mid,13,14,15,16);
    if(id==5) swap(mid,1,5,9,13);
    if(id==6) swap(mid,2,6,10,14);
    if(id==7) swap(mid,3,7,11,15);
    if(id==8) swap(mid,4,8,12,16);
    if(id==9) swap(mid,16,12,8,4);
    if(id==10) swap(mid,15,11,7,3);
    if(id==11) swap(mid,14,10,6,2);
    if(id==12) swap(mid,13,9,5,1);
    if(id==13) swap(mid,16,15,14,13);
    if(id==14) swap(mid,12,11,10,9);
    if(id==15) swap(mid,8,7,6,5);
    if(id==16) swap(mid,4,3,2,1);
}
bool dfs(int* mid ,int dep, int fa)
{
    if(counts(mid)==0) return 1;
    if(dep+counts(mid)>t) return 0;//最少需要
    for(int i=1;i<17;i++)
    {
        if(!isok(i,fa)) continue;
        swap(mid,i);
        if(dfs(mid,dep+1,i)) return 1;
        swap(mid,17-i);
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        for(int i=1;i<17;i++) scanf("%d",&map[i]);
        for(t=0;t<=5;t++)//t为层数限制
        {
            if(dfs(map,0,-1)) break;
        }
        if(t>5) puts("-1");
        else printf("%d\n",t);
    }
    return 0;
}
