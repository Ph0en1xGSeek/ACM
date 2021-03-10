#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#define MAXT 2003
#define inf 1000000000

using namespace std;

int ap[MAXT], bp[MAXT], as[MAXT], bs[MAXT];
int dp[MAXT][MAXT];
int q[MAXT];

int main() {
    int t, T, MaxP, W, next_day;
    int top, tail;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &T, &MaxP, &W);
        for(int i = 0; i <= T; ++i) {
            for(int j = 0; j <= MaxP; ++j) {
                dp[i][j] = -inf;
            }
        }
        dp[0][0] = 0;
        ++W;
        for(int i = 0; i < T; ++i) {
            scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
        }
        for(int i = 0; i < T; ++i) {
            if(i > 0) {
                for(int j = 0; j <= MaxP; ++j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
            }
            next_day = i + W > T? T: i+W;
            // buy
            q[top = tail = 0] = 0;
            for(int j = 1; j <= MaxP; ++j) {
                while(q[tail] + as[i] < j) {
                    ++tail;
                }
                dp[next_day][j] = max(dp[next_day][j], dp[i][q[tail]] - ap[i] * (j - q[tail]));
                while(dp[i][q[top]] - ap[i] * (j - q[top]) <= dp[i][j] && tail <= top) {
                    --top;
                }
                q[++top] = j;
            }
            //sell
            q[top = tail = 0] = MaxP;
            for(int j = MaxP-1; j >= 0; --j) {
                while(q[tail] - bs[i] > j) {
                    ++tail;
                }
                dp[next_day][j] = max(dp[next_day][j], dp[i][q[tail]] + bp[i] * (q[tail] - j));
                while(dp[i][q[top]] + bp[i] * (q[top] - j) <= dp[i][j] && tail <= top) {
                    --top;
                }
                q[++top] = j;
            }
        }
        printf("%d\n", max(dp[T-1][0], dp[T][0]));
    }
    return 0;
}