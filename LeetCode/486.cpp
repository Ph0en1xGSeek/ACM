class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sz = nums.size();
        if((sz & 1) == 0 || sz == 1) {
            return true;
        }
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        dp[0][0] = nums[0];
        for(int i = 1; i < sz; ++i) {
            dp[i-1][i] = abs(nums[i] - nums[i-1]);
            dp[i][i] = nums[i];
        }
        for(int i = sz-1; i >= 0; --i) {
            for(int j = i + 2; j < sz; ++j) {
                int tmp1 = nums[i] - nums[i+1] + dp[i+2][j];
                tmp1 = min(tmp1, nums[i] - nums[j] + dp[i+1][j-1]);
                int tmp2 = nums[j] - nums[j-1] + dp[i][j-2];
                tmp2 = min(tmp2, nums[j] - nums[i] + dp[i+1][j-1]);
                dp[i][j] = max(tmp1, tmp2);
            }
        }
        return (dp[0][sz-1] > 0);
    }
};