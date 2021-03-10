#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int INT_MAX = 0x7fffffff;
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int states = (1 << n);
    vector<vector<int>> dp(states, vector<int>(n, INT_MAX));
    dp[1][0] = 0;
    for(int i = 1; i < states; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dp[i][j] == INT_MAX) {
                continue;
            }
            for(int k = 0; k < n; ++k) {
                if((i & (1 << k)) == 0) {
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + arr[j][k]);
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i) {
        if(dp[states - 1][i] == INT_MAX) {
            continue;
        }
        ans = min(ans, dp[states-1][i] + arr[i][0]);
    }
    if(ans == INT_MAX) {
        cout << -1 << endl;
    }else {
        cout << ans << endl;
    }
    return 0;
}