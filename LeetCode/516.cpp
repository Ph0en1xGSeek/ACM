class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        vector<vector<int>> dp(2, vector<int>(sz, 0));
        int cur = 0;
        for(int i = sz-1; i >= 0; --i) {
            cur = 1 - cur;
            dp[cur][i] = 1;
            for(int j = i+1; j < sz; ++j) {
                if(s[i] == s[j]) {
                    dp[cur][j] = dp[1-cur][j-1] + 2;
                }else {
                    dp[cur][j] = max(dp[cur][j-1], dp[1-cur][j]);
                }
            }
        }
        return dp[cur][sz-1];
    }
};