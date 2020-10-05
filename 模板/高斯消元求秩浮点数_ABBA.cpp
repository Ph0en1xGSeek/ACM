#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-4

using namespace std;

const int MAXN=220;
double a[MAXN][MAXN];
int equ,var;

int gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r=i;
        }
        if(fabs(a[max_r][col])<eps)
        {
            k--;///本列的主元没找到 行不变 列+1
            continue;
        }
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
                 swap(a[k][j],a[max_r][j]);
        }
        for(j=col+1;j<var;j++)
            a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
            if(i!=k)
            {
                for(j=col+1;j<var;j++)
                    a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return k;
}

int main()
{
    while(scanf("%d%d",&equ,&var)!=EOF)
    {
        for(int i=0;i<equ;i++){
            for(int j=0;j<var;j++)
                scanf("%lf",&a[i][j]);
        }

        int ans = gauss();
        cout << ans << endl;
    }
    return 0;
}
