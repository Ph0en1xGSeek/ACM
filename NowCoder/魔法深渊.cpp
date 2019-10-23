#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mod 1000000003

using namespace std;

int main() {
    int dp[1003];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 1000; ++i) {
        int tmp = 1;
        while(i - tmp >= 0) {
            dp[i] = (dp[i] + dp[i - tmp]) % mod;
            tmp <<= 1;
        }
    }
    int ca, n;
    scanf("%d", &ca);
    while(ca--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}