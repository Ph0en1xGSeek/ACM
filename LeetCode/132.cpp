class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len == 0){
            return 0;
        }
        vector<int> dp(len, 0);
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++){
            dp[i] = i;
            for(int j = 0; j <= i; j++){
                if(s[i] == s[j] && (i-j <= 1 || isPalindrome[j+1][i-1])){
                    isPalindrome[j][i] = true;
                    if(j == 0){
                        dp[i] = 0;
                    }else{
                        dp[i] = min(dp[i], dp[j-1] + 1);
                    }
                }
            }
        }
        return dp[len-1];
    }
};