#include <iostream>
#include <vector>

using namespace std;

const int INT_MAX = 0x3fffffff;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        dp[i-1][i-1] = 0;
    }
    for(int j = 1; j < n; ++j) {
        for(int i = 0; i + j < n; ++i) {
            for(int k = i; k < i + j; ++k) {
                dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k+1][i+j] + arr[i + j + 1] - arr[i]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}