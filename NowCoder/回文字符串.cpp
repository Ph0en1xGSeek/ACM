#include <iostream>
#include <stdio.h>

using namespace std;

int dp[1005][1005] = {0};

int main() {
    string str;
    cin >> str;
    int sz = str.size();
    int ans = 1;
    for(int r = 0; r < sz; ++r) {
        dp[r][r] = 1;
        for(int l = r-1; l >= 0; --l) {
            if(str[l] == str[r]) {
                dp[l][r] = dp[l+1][r-1] + 2;
            }else {
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
            ans = max(ans, dp[l][r]);
        }
    }
    printf("%d\n", ans);
    return 0;
}