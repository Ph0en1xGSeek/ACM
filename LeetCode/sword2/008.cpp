class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(j < size) {
            while (j < size && sum < target) {
                sum += nums[j++];
            }
            while (i < j && sum - nums[i] >= target) {
                sum -= nums[i++];
            }
            if (sum >= target) {
                ans = min(ans, j - i);
                if (i < j) {
                    sum -= nums[i++];
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};