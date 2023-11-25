class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int size1 = text1.length();
        int size2 = text2.length();
        if (size1 == 0 || size2 == 0) {
            return 0;
        }

        vector<vector<int>> dp(2, vector<int>(size2 + 1));
        int cur = 0;
        for (int i = 1; i <= size1; ++i) {
            cur ^= 1;
            for (int j = 1; j <= size2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[cur][j] = dp[cur ^ 1][j - 1] + 1;
                } else {
                    dp[cur][j] = max(dp[cur ^ 1][j], dp[cur][j - 1]);
                }
            }
        }
        return dp[cur][size2];
    }
};