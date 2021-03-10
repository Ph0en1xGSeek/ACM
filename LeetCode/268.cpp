class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        for(int i = 0; i < sz; ++i) {
            sum += nums[i];
        }
        int tot = (sz + 1) * sz / 2;
        int ans = tot - sum;
        return ans;
    }
};