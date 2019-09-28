#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int a[101];
int c[101];
int w[1001];
bool dp[100001];


int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m) && n != 0) {

        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; c[i] > 0; j <<= 1) {
                int tmp = min(c[i], j);
                w[cnt++] = tmp*a[i];
                c[i] -= tmp;
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i < cnt; ++i) {
            for(int j = m; j >= w[i]; --j) {
                if(dp[j - w[i]]) {
                    dp[j] = true;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            if(dp[i])
                ++ans;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}