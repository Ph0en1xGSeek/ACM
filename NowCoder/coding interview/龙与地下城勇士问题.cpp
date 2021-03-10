#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
        }
        vector<int> dp(m, 0x7fffffff);
        dp[m-1] = 1;
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                if(j != m-1) {
                    dp[j] = min(dp[j], dp[j+1]);
                }
                dp[j] -= arr[i][j];
                if(dp[j] <= 0) {
                    dp[j] = 1;
                }
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}