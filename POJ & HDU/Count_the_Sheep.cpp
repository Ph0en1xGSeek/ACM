///枚举长度为3的路径，二分图不存在三元环
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define M 250000

using namespace std;

vector<int> nex[M];
int main()
{
    int ca, n, m, k;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n+m; i++)
            nex[i].clear();
        for(int i = 0; i < k; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            nex[a-1].push_back(b+n-1);
            nex[b+n-1].push_back(a-1);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < nex[i].size(); j++)
            {
                ans += ((nex[i].size()-1) * (nex[nex[i][j]].size()-1));
            }
        }
        printf("%lld\n", ans*2);
    }
    return 0;
}
