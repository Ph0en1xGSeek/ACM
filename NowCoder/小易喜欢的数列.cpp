#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main() {
    int n, k;
    while(cin >> n >> k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][1] = 1;
        for(int i = 1; i <= n; ++i) {
            int sum = 0;
            for(int j = 1; j <= k; ++j) {
                sum = (sum + dp[i-1][j]) % mod;
            }
            for(int j = 1; j <= k; ++j) {
                int p = 2;
                int invalid = 0;
                while(j * p <= k) {
                    invalid = (invalid + dp[i-1][j*p]) % mod;
                    ++p;
                }
                dp[i][j] = (sum - invalid + mod) % mod;
            }
        }
        int ans = 0;
        for(int j = 1; j <= k; ++j) {
            ans = (ans + dp[n][j]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}