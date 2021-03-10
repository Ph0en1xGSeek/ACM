#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ca, n, k;
    cin >> ca;
    while(ca--) {
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[0][0] = true;
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >= 0 && j >= i - k; --j) {
                if(arr[j] >= arr[i]) {
                    dp[i][0] = dp[i][0] || dp[j][0];
                    dp[i][1] = dp[i][1] || dp[j][1];
                }
                dp[i][1] = dp[i][1] || dp[j][0];
            }
        }
        if(dp[n-1][0] || dp[n-1][1]) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}