class Solution {
public:
    int waysToChange(int n) {
        if(n == 0) {
            return 0;
        }
        int coins[4] = {1, 5, 10, 25};
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < 4; ++i) {
            for(int j = coins[i]; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }
      return dp[n];
    }
};