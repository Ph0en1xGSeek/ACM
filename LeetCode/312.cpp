class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size() + 2;
        vector<int> new_nums(sz);
        new_nums[0] = new_nums[sz-1] = 1;
        for(int i = 1; i < sz-1; ++i) {
            new_nums[i] = nums[i-1];
        }
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for(int left = sz-3; left >= 0; --left) {
            for(int right = left + 2; right < sz; ++right) {
                for(int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + new_nums[left] * new_nums[i] * new_nums[right]);
                }
            }
        }
        return dp[0][sz-1];
    }
};