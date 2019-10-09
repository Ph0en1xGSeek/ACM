#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>

using namespace std;

int a[101];
int c[101];
int dp[100001];
int q[100001];

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m) && n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            int tmp = a[i] * c[i];
            for(int j = 0; j < a[i]; ++j) {
                if(dp[j])
                    q[j] = j;
                else
                    q[j] = -1;
            }
            for(int j = a[i]; j <= m; ++j) {
                if(dp[j]) {
                    q[j] = j;
                }else {
                    q[j] = q[j - a[i]];
                    if(q[j] >= 0 && q[j] + tmp >= j)
                        dp[j] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <=m; ++i) {
            cnt += dp[i];
        }
        printf("%d\n", cnt);
    }
    return 0;
}