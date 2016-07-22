#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[101];
int sg[10001];
int v[10001];


int n,m;
int dfs(int s)//sg����ֵ
{
    if(v[s]==1)//ȷ������sg,���仯����
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

/*1.�ɽ�����ת��Ϊn�������⣬ÿ��������ֱ�Ϊ��
   ��һ��x��ʯ����ȡʯ�ӣ�ÿ�ο�ȡ��ʯ����Ϊ����S(k)�е�һ����
 2.����(1)�е�ÿ�������⣬
   �׵�:SG(x) = mex(SG[x-s[i]])(0<i<k-1);
 3.�������SG������Ӧ�ã�����Sprague-Grundy Therem��g(G)=g(G1)^g(G2)^g(G3)^...^g(Gn)
   ����Ϸ�ĺ͵�SG����ֵ��������������Ϸ��SG����ֵ����򣬼�
   SG(G) = SG(x1)^SG(x2)^...^SG(xn),����SG(G)=0��ô����*/
