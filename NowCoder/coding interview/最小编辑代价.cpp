#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str1, str2;
    int ic, dc, rc;
    while(cin >> str1 >> str2) {
        cin >> ic >> dc >> rc;
        int size1 = str1.size();
        int size2 = str2.size();
        vector<vector<int>> dp(2, vector<int>(size2+1, 0));
        int cur = 0;
        for(int i = 1; i <= size2; ++i) {
            dp[cur][i] = ic * i;
        }
        for(int i = 1; i <= size1; ++i) {
            cur = 1 - cur;
            dp[cur][0] = dc * i;
            for(int j = 1; j <= size2; ++j) {
                if(str1[i-1] == str2[j-1]) {
                    dp[cur][j] = dp[1-cur][j-1];
                }else {
                    dp[cur][j] = dp[1-cur][j-1] + rc;
                    dp[cur][j] = min(dp[cur][j], dp[1-cur][j] + dc);
                    dp[cur][j] = min(dp[cur][j], dp[cur][j-1] + ic);
                }
            }
        }
        cout << dp[cur][size2] << endl;
    }
    return 0;
}