#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#include <map>

#define N 1000004

long long x[N];
int q[N];
long long dp[N];
long long n, c;

using namespace std;

long long getnum(int from, int to) {
    long long dis = x[to] - x[from+1];
    return c + dis * dis + dp[from];
}

int getx(int line1, int line2) {
    double a = dp[line2] + x[line2+1] * x[line2+1] - dp[line1] - x[line1+1] * x[line1+1];
    return a / (x[line2+1] - x[line1+1]);
}

int main() {
    x[0] = 0;
    dp[0] = 0;
    while(~scanf("%I64d%I64d", &n, &c) && n) {
        scanf("%I64d", &x[1]);
        int head = 0, tail = 1;
        q[head] = 0;
        q[tail] = 1;
        dp[1] = c;
        for(int i = 2; i <= n; ++i) {
            scanf("%I64d", &x[i]);
            while(head + 2 <= tail && getx(q[tail-1], q[tail]) <= getx(q[tail-2], q[tail-1])) {
                q[tail-1] = q[tail];
                --tail;
            }
            while(head < tail && getnum(q[head], i) >= getnum(q[head+1], i)) {
                ++head;
            }
            dp[i] = getnum(q[head], i);
            q[++tail] = i;
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}