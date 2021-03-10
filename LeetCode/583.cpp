class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 < size2) {
            swap(size1, size2);
            swap(word1, word2);
        }
        vector<vector<int>> dp(2, vector<int>(size2 + 1, 0));
        int cur = 0;
        for(int i = 0; i <= size2; ++i) {
            dp[cur][i] = i;
        }
        for(int i = 1; i <= size1; ++i) {
            cur = 1 - cur;
            dp[cur][0] = i;
            for(int j = 1; j <= size2; ++j) {
                if(word1[i-1] == word2[j-1]) {
                    dp[cur][j] = dp[1- cur][j-1];
                }else {
                    dp[cur][j] = min(dp[cur][j-1], dp[1 - cur][j]) + 1;
                }
            }
        }
        return dp[cur][size2];
    }
};