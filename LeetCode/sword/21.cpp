class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return nums;
        }
        int l = 0;
        int r = size - 1;
        while (l < r) {
            if ((nums[l] & 1) == 0) {
                swap(nums[l], nums[r]);
                --r;
            } else {
                ++l;
            }
        }
        return nums;
    }
};