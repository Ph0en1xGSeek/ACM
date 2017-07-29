#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mod=1000000007;

long long multi(long long a, long long b)
{
    long long ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret = (ret*a)%mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}//pow(a, b) mod m

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,b;
        scanf("%I64d%I64d",&n,&b);
        long long m=0;
        long long tmp=b;
        while(tmp)
        {
            m++;
            tmp/=10;
        }
        long long ans=((((multi(10,n*m)-1)*b)%mod)*(multi(multi(10, m)-1, mod-2)))%mod;
        cout<<ans<<endl;
    }
    return 0;
}






















