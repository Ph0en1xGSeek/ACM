#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#define MAX_INT 0x3f3f3f3f

using namespace std;

int arr[11][11];
int dp[60000][11];
int pow3[11];

int main() {
    int n, m;
    int a, b, c;
    int tmp = 1;
    for(int i = 0; i <= 10; ++i) {
        pow3[i] = tmp;
        tmp *= 3;
    }
    while(~scanf("%d%d", &n, &m)) {
        memset(arr, 0x3f, sizeof(arr));
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            arr[a-1][b-1] = arr[b-1][a-1] = min(arr[a-1][b-1], c);
        }
        for(int i = 0; i < n; ++i) {
            dp[pow3[i]][i] = 0;
        }
        int ans = MAX_INT;
        for(int i = 1; i < pow3[n]-1; ++i) {
            bool flag = true;
            for(int j = 0; j < n; ++j) {
                if((i / pow3[j]) % 3 == 0) {
                    flag = false;
                    continue;
                }
                for(int k = 0; k < n; ++k) {
                    if((i / pow3[k]) % 3 < 2) {
                        dp[i + pow3[k]][k] = min(dp[i + pow3[k]][k], dp[i][j] + arr[j][k]);
                    }
                }
            }
            if(flag) {
                for(int j = 0; j < n; ++j) {
                    ans = min(ans, dp[i][j]);
                }
            }

        }
        if(ans == MAX_INT) {
            printf("-1\n");
        }else {
            printf("%d\n", ans);
        }
    }
    return 0;
}