#include <iostream>
#include <vector>

using namespace std;

int main() {
    const long long mod = 1e9 + 7;
    string str;
    string target;
    cin >> str >> target;
    int size = str.size();
    if(size == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<vector<long long>>> dp(size/2 + 1, vector<vector<long long>>(size/2 + 1, vector<long long>(2, 0)));
    for(int i = 0; i < size; i += 2) {
        if(str[i] == '1') {
            dp[i>>1][i>>1][1] = 1;
            dp[i>>1][i>>1][0] = 0;
        }else if(str[i] == '0') {
            dp[i>>1][i>>1][1] = 0;
            dp[i>>1][i>>1][0] = 1;
        }else {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int span = 2; span < size; span += 2) {
        for(int i = 0; i + span < size; i += 2) {
            for(int j = i + 1; j < i + span; j += 2) {
                if(str[j] == '^') {
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                }else if(str[j] == '&') {
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                }else if(str[j] == '|') {
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][0] = (dp[i>>1][(i + span)>>1][0] + (dp[i>>1][(j-1)>>1][0] * dp[(j+1)>>1][(i+span)>>1][0]) % mod) % mod;
                    dp[i>>1][(i + span)>>1][1] = (dp[i>>1][(i + span)>>1][1] + (dp[i>>1][(j-1)>>1][1] * dp[(j+1)>>1][(i+span)>>1][1]) % mod) % mod;
                }
            }
        }
    }
    if(target == "true") {
        cout << dp[0][size / 2][1] << endl;
    }else {
        cout << dp[0][size / 2][0] << endl;
    }
    return 0;
}