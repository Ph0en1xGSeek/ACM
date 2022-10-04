class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int sum = nums[0];
        int mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};