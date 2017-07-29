#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define M 100010
#include <map>

using namespace std;

int arr[M];
int dp[M][17];
map<int, long long> m;
int num;

void st() ///初始化RMQ
{
    for(int i = 1; i <=num; i++)
        dp[i][0] = arr[i];
    for(int j = 1; (1<<j)<= num; j++)
        for(int i = 1; i + (1<<j)-1 <= num; i++)
        {
            dp[i][j] = __gcd(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
}

int query(int l, int r)
{
    int x = (int)log2(r-l+1);
    return __gcd(dp[l][x], dp[r-(1<<x)+1][x]);
}

int main()
{
    int t, q;
    int a, b;
    int val;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        m.clear();
        scanf("%d", &num);
        for(int j = 1; j <= num; j++)
            scanf("%d", &arr[j]);
        st();
        for(int j = 1; j <= num; j++)///在m中预先存好每种gcd值得区间数
        {
            int pos = j;
            while(pos <= num)
            {
                val = query(j, pos);
                int l = pos, r = num;
                int mid;
                while(l <= r)///二分查找 l为第一个gcd小于目前区间的右端点
                {
                    mid = (l+r) >> 1;
                    if(query(j, mid) == val)  l = mid + 1;
                    else    r = mid - 1;
                }
                m[val] += l - pos;
                pos = l;
            }
        }
        scanf("%d", &q);
        printf("Case #%d:\n", i);
        while(q--)
        {
            scanf("%d%d", &a, &b);
            int tmp = query(a, b);
            printf("%d %lld\n", tmp, m[tmp]);
        }
    }
    return 0;
}
