class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int> > dp;
        for(int i = 0; i <= len1; i++){
            vector<int> dpi;
            for(int j = 0; j <= len2; j++){
                if(i == 0){
                    dpi.push_back(j);
                }else if(j == 0){
                    dpi.push_back(i);
                }else{
                    dpi.push_back(0);
                }
            }
            dp.push_back(dpi);
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int mi = min(dp[i-1][j], dp[i][j-1]);
                    mi = min(mi, dp[i-1][j-1]);
                    dp[i][j] = mi + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};