class Solution {
public:
    int minInsertions(string s) {
        int size = s.size();
        vector<vector<int>> dp(2, vector<int>(size, 0));
        int cur = 0;
        for(int i = size-1; i >= 0; --i) {
            cur = 1 - cur;
            dp[cur][i] = 1;
            for(int j = i + 1; j < size; ++j) {
                if(s[i] == s[j]) {
                    dp[cur][j] = dp[1 - cur][j - 1] + 2;
                }else {
                    dp[cur][j] = max(dp[1 - cur][j], dp[cur][j - 1]);
                }
            }
        }
        return size - dp[cur][size - 1];
    }
};