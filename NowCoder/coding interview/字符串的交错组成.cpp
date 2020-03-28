#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    string str1, str2, aim;
    while(cin >> str1 >> str2 >> aim) {
        int size1 = str1.size();
        int size2 = str2.size();
        int size = aim.size();
        if(size1 + size2 != size) {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<bool>> dp(2, vector<bool>(size2 + 1, 0));
        dp[0][0] = true;
        int cur = 0;
        for(int i = 1; i <= size2; ++i) {
            dp[0][i] = (dp[0][i-1] && (str2[i-1] == aim[i-1]));
        }
        for(int i = 1; i <= size1; ++i) {
            cur = 1 - cur;
            dp[cur][0] = (dp[1-cur][0] && str1[i-1] == aim[i-1]);
            for(int j = 1; j <= size2; ++j) {
                dp[cur][j] = (str1[i-1] == aim[i+j-1] && dp[1-cur][j]) ||
                             (str2[j-1] == aim[i+j-1] && dp[cur][j-1]);
            }
        }
        if(dp[cur][size2]) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}