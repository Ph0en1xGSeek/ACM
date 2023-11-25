class Solution {
public:
    int minCut(string s) {
        int size = s.length();
        vector<vector<bool>> isPalidrome(size, vector<bool>(size, true));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                isPalidrome[i][j] = (s[i] == s[j]) && isPalidrome[i + 1][j - 1];
            }
        }
        vector<int> dp(size, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < size; ++i) {
            if (isPalidrome[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = i - 1; j >= 0; --j) {
                if (isPalidrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};