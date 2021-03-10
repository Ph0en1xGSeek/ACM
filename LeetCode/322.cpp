class Solution {
private:
    vector<int> dp;
public:
    int dfs(vector<int> &coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(dp[amount] >= 0) {
            return dp[amount];
        }
        int ans = 0x7ffffffe;
        for(int i = coins.size()-1; i >= 0; --i) {
            if(amount - coins[i] >= 0) {
                ans = min(dfs(coins, amount - coins[i]) + 1, ans);
            }
        }
        dp[amount] = ans;
        return ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int sz = coins.size();
        dp.resize(amount+1, -1);
        dp[0] = 0;
        int ans = 0x7ffffffe;
        
        ans = min(dfs(coins, amount), ans);
        if(ans >= 0x7ffffffe) {
            ans = -1;
        }
        return ans;
    }
};