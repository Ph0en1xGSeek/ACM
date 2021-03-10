#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int sum,now,n,ans;
multiset <int> hash;
void solve()
{
    hash.clear();
    scanf("%d",&n);
    sum=ans=0;
    hash.insert(0);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&now);
        sum=now+sum;
        ans+=hash.count(sum-47);
        hash.insert(sum);
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    solve();
    return 0;
}
