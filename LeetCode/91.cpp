class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                if(i > 1){
                    dp[i] += dp[i-2];
                }else{
                    dp[i] = 1;
                }
            }
            if(s[i] > '0'){
                dp[i] += dp[i-1];
            }
        }
        return dp[s.length()-1];
    }
};