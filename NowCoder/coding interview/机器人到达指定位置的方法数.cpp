#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, p;
    const int Mod = 1000000007;
    while(cin >> n >> m >> k >> p) {
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int cur = 0;
        dp[0][m-1] = 1;
        for(int i = 0; i < k; ++i) {
            cur = 1 - cur;
            for(int j = 0; j < n; ++j) {
                dp[cur][j] = 0;
                if(j > 0) {
                    dp[cur][j] = (dp[1 - cur][j - 1] + dp[cur][j]) % Mod;
                }
                if(j < n-1) {
                    dp[cur][j] = (dp[1 - cur][j + 1] + dp[cur][j]) % Mod;
                }
            }
        }
        cout << dp[cur][p-1] << endl;
    }
    return 0;
}