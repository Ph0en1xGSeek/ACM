class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        for(int i = 0; i < sz; ++i) {
            sum += nums[i];
        }
        if(sum & 1) {
            return false;
        }
        int target = sum >> 1;
        vector<bool> dp(target+1, 0);
        dp[0] = true;
        for(int i = 0; i < sz; ++i) {
            for(int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};