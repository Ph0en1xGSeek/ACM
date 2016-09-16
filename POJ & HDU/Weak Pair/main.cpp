#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100100
#include <vector>

using namespace std;

const long long INF = 1000000000000000000;

int n;
int arr[M], father[M], cnt[M<<1];
long long seq[M<<1], ans, k;
vector<int> son[M];

int lowbit(int x)
{
    return x & (-x);
}

void dfs(int x)
{
    int key;
    if(arr[x] == 0)
        key = lower_bound(seq+1, seq+2*n+1, INF) - seq;
    else
        key = lower_bound(seq+1, seq+2*n+1, k/arr[x]) - seq;
    long long tmp2 = 0;
    while(key)
    {
        tmp2 += cnt[key];
        key -= lowbit(key);
    }
    ans += tmp2;
    key = lower_bound(seq+1, seq+2*n+1, arr[x])-seq;
    int tmp = key;
    while(tmp <= 2*n)
    {
        cnt[tmp]++;
        tmp += lowbit(tmp);
    }
    tmp = son[x].size();
    for(int i = 0; i < tmp; i++)
        dfs(son[x][i]);
    while(key <= 2*n)
    {
        cnt[key]--;
        key += lowbit(key);
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        memset(father, 0, sizeof(father));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%I64d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            son[i].clear();
            scanf("%d", &arr[i]);
            seq[i] = arr[i];
        }
        for(int i = n+1; i <= 2*n; i++)
            if(seq[i-n] == 0)
                seq[i] = INF;
            else
                seq[i] = k/seq[i-n];
        sort(seq+1, seq+n*2+1);
        int a, b;
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d%d", &a, &b);
            father[b] = a;
            son[a].push_back(b);
        }
        for(int i = 1; i <= n; i++)
            if(father[i] == 0)
            {
                dfs(i);
                break;
            }
        printf("%I64d\n", ans);
    }
    return 0;
}
