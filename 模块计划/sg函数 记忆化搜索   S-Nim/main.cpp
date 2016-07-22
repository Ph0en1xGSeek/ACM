#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[101];
int sg[10001];
int v[10001];


int n,m;
int dfs(int s)//sg函数值
{
    if(v[s]==1)//确定过的sg,记忆化搜索
        return sg[s];
    v[s]=1;
    bool v2[20001]={0};

    for(int i=1;i<=n;i++)
        if(s>=a[i])
        {
            int j = dfs(s-a[i]);
            v2[j]=1;
        }
    sg[s]=0;
    for(int i=0; ; i++)
        if(v2[i]==0)
        {
            sg[s]=i;
            break;
        }
    return sg[s];
}

int main()
{
    int SG, k, t;
    while(scanf("%d", &n), n)
    {
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        v[0]=1;
        for(int s=1;s<=m;s++)
        {
            scanf("%d",&k);

            SG = 0;
            for(int i=1;i<=k;i++)
            {
                scanf("%d",&t);
                SG^=dfs(t);
            }
            if(SG == 0)
                cout<<'L';
            else
                cout<<'W';
        }
        cout<<endl;
    }
    return 0;
}

/*1.可将问题转化为n个子问题，每个子问题分别为：
   从一堆x颗石子中取石子，每次可取的石子数为集合S(k)中的一个数
 2.分析(1)中的每个子问题，
   易得:SG(x) = mex(SG[x-s[i]])(0<i<k-1);
 3.后面就是SG函数的应用，根据Sprague-Grundy Therem：g(G)=g(G1)^g(G2)^g(G3)^...^g(Gn)
   即游戏的和的SG函数值是它的所有子游戏的SG函数值的异或，即
   SG(G) = SG(x1)^SG(x2)^...^SG(xn),故若SG(G)=0那么必输*/
