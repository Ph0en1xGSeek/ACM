#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#include <map>

#define N 100007
#define M 300007
#define mod 9901

using namespace std;

int arr[N];
int num[M];
int tree[M];
map<int, int> mp;

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int num) {
    while(pos < M) {
        tree[pos] += num;
        tree[pos] %= mod;
        pos += lowbit(pos);
    }
}

int sum(int pos) {
    int ans = 0;
    while(pos > 0) {
        ans += tree[pos];
        ans %= mod;
        pos -= lowbit(pos);
    }
    return ans;
}

int main() {
    int n, d;
    while(~scanf("%d%d", &n, &d)) {
        memset(tree, 0, sizeof(tree));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            num[3 * i] = arr[i];
            num[3 * i + 1] = arr[i] + d;
            num[3 * i + 2] = arr[i] - d - 1;
        }
        sort(num, num + 3 * n);
        int cnt = unique(num, num + 3 * n) - num;
        mp.clear();
        for(int i = 0; i < cnt; ++i) {
            mp[num[i]] = i+1;
        }
        int x;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            x = sum(mp[arr[i] + d]) - sum(mp[arr[i] - d - 1]);
            x %= mod;
            x = (x + mod) % mod;
            ans = (ans + x) % mod;
            add(mp[arr[i]], (x+1) % mod);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}