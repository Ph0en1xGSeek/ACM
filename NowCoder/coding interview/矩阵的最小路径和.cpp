#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(2, vector<int>(m, 0));
    int arr;
    int cur = 0;
    for(int j = 0; j < m; ++j) {
        cin >> arr;
        if(j > 0)
            dp[cur][j] = dp[cur][j-1] + arr;
        else
            dp[cur][j] = arr;
    }
    for(int i = 1; i < n; ++i) {
        cur = 1 - cur;
        cin >> arr;
        dp[cur][0] = dp[1-cur][0] + arr;
        
        for(int j = 1; j < m; ++j) {
            cin >> arr;
            dp[cur][j] = min(dp[1-cur][j], dp[cur][j-1]) + arr;
        }
    }
    cout << dp[cur][m-1] << endl;
    return 0;
}