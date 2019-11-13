class Solution {
public:
    vector<int> dp;
    
    int dfs(vector<int> &nums, int target) {
        if(dp[target] != -1) {
            return dp[target];
        }
        dp[target] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(target - nums[i] >= 0) {
                dp[target] += dfs(nums, target - nums[i]);
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) {
            return 0;
        }
        dp.resize(target+1, -1);
        dp[0] = 1;
        return dfs(nums, target);
    }
};