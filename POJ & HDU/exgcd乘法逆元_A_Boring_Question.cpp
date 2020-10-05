#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD=1000000007;

long long multi(long long a,long long b)
{
    long long ret=1;
    while(b>0)
    {
        if(b&1)
            ret=a*ret%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return ret;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long ret=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m;
        scanf("%I64d%I64d",&n,&m);
        long long x1=multi(m,(n+1))-1;
        long long x2=m-1;///x1/x2等比数列和 但要求逆元
        long long x,y;
        exgcd(x2,MOD,x,y);
        long long x3=(x%MOD+MOD)%MOD;///乘法逆元
        long long ans=(x1*x3)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

