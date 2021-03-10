#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 2*100005
#define INF 0x7fffffff

using namespace std;

struct node
{
    int p;
    int len;
    int cost;
    int type;
    bool operator<(const node& b) const
    {
        if(p != b.p) return p < b.p;
        else
            return type < b.type;
    }
}arr[2*M];

int dp[M];

int main() {


    long long ans;
    int n, x;
    int a, b, c;
    int cnt;
    while (scanf("%d%d", &n, &x) != EOF)
    {
        for(int i = 0; i <= x; i++)
            dp[i] = INF;
        ans = INF;
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            arr[cnt].p = a;
            arr[cnt].len = b - a + 1;
            arr[cnt].cost = c;
            arr[cnt++].type = -1;
            arr[cnt].p = b;
            arr[cnt].len = b - a + 1;
            arr[cnt].cost = c;
            arr[cnt++].type = 1;
        }
        sort(arr, arr+cnt);
        for(int i = 0; i < cnt; i++)
        {
            if(arr[i].type == 1)
            {
                if(arr[i].cost < dp[arr[i].len])
                    dp[arr[i].len] = arr[i].cost;
            }
            else if(arr[i].type == -1)
                if(arr[i].len < x)
                    ans = min(ans, (long long)arr[i].cost + (long long)dp[x-arr[i].len]);
        }
        if(ans >= INF)
            printf("-1\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}