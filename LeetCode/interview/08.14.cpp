class Solution {
public:
    int countEval(string s, int result) {
        int size = s.size();
        vector<char> oprand(size / 2 + 1);
        vector<char> opera(size / 2);
        for(int i = 0; i < size-1; i += 2) {
            oprand[i >> 1] = s[i];
            opera[i >> 1] = s[i + 1];
        }
        oprand[size / 2] = s[size - 1];
        size = size / 2 + 1;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(2, 0)));
        for(int i = 0; i < size; ++i) {
            if(oprand[i] == '0') {
                dp[i][i][0] = 1;
            }else {
                dp[i][i][1] = 1;
            }
        }
        for(int k = 1; k <= size - 1; ++k) {
            for(int i = 0; i + k < size; ++i) {
                for(int j = i; j < i + k; ++j) {
                    if(opera[j] == '&') {
                        dp[i][i+k][1] += dp[i][j][1] * dp[j+1][i+k][1];
                        dp[i][i+k][0] += dp[i][j][0] * dp[j+1][i+k][0];
                        dp[i][i+k][0] += dp[i][j][1] * dp[j+1][i+k][0];
                        dp[i][i+k][0] += dp[i][j][0] * dp[j+1][i+k][1];
                    }else if(opera[j] == '|') {
                        dp[i][i+k][1] += dp[i][j][1] * dp[j+1][i+k][1];
                        dp[i][i+k][0] += dp[i][j][0] * dp[j+1][i+k][0];
                        dp[i][i+k][1] += dp[i][j][1] * dp[j+1][i+k][0];
                        dp[i][i+k][1] += dp[i][j][0] * dp[j+1][i+k][1];
                    }else {
                        dp[i][i+k][0] += dp[i][j][1] * dp[j+1][i+k][1];
                        dp[i][i+k][0] += dp[i][j][0] * dp[j+1][i+k][0];
                        dp[i][i+k][1] += dp[i][j][1] * dp[j+1][i+k][0];
                        dp[i][i+k][1] += dp[i][j][0] * dp[j+1][i+k][1];
                    }
                }
            }
        }
        return dp[0][size-1][result];
    }
};