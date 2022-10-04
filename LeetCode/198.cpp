class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        if(len > 1){
            dp[1] = max(nums[0], nums[1]);
        }
        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[len-1];
    }
};