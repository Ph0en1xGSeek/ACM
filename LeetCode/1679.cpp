class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> nums_cnt;
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (nums_cnt[k - nums[i]] > 0) {
                nums_cnt[k - nums[i]]--;
                ++ans;
            } else {
                nums_cnt[nums[i]]++;
            }
        }
        return ans;
    }
};