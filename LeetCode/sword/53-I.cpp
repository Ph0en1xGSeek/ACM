class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        return upper - lower;
    }
};