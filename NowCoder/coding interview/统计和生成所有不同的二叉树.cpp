#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    const long long mod = 1e9 + 7;
    cin >> n;
    if(n < 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % mod) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}