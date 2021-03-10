#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int INT_MAX = 0x7fffffff;
    int num;
    while(cin >> num) {
        vector<int> isCom(num, false);
        vector<int> isGym(num, false);
        for(int i = 0; i < num; ++i) {
            cin >> isCom[i];
        }
        for(int i = 0; i < num; ++i) {
            cin >> isGym[i];
        }
        vector<vector<int>> dp(2, vector<int>(3, INT_MAX));
        dp[0][0] = 1;
        dp[0][1] = isCom[0]? 0: INT_MAX;
        dp[0][2] = isGym[0]? 0: INT_MAX;
        int cur = 0;
        for(int i = 1; i < num; ++i) {
            cur = 1 - cur;
            dp[cur][0] = min(dp[1 - cur][0], dp[1 - cur][1]);
            dp[cur][0] = min(dp[cur][0], dp[1 - cur][2]);
            ++dp[cur][0];
            dp[cur][1] = isCom[i]? min(dp[1-cur][0], dp[1-cur][2]): INT_MAX;
            dp[cur][2] = isGym[i]? min(dp[1-cur][0], dp[1-cur][1]): INT_MAX;
        }
        int ans = min(dp[cur][0], dp[cur][1]);
        ans = min(ans, dp[cur][2]);
        cout << ans << endl;
    }
    return 0;
}