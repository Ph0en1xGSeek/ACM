#include <iostream>
#include <stdio.h>
#include <algorithm>
#define Max 200010
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    int ca, n, m, k, tmp;
    long long ans;
    scanf("%d", &ca);
    while(ca--)
    {
        v.clear();
        v.push_back(-1);
        ans = 0;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if(tmp >= m) v.push_back(i);
        }
        for(int i = 1; i+k-1 < v.size(); i++)
        {
            ans += (long long)(v[i]-v[i-1]) * (long long)(n-v[i+k-1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
