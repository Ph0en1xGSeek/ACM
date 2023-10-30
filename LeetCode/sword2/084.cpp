class Solution {
public:
    bool nextPermutation(vector<int> &nums) {
        int size = nums.size();
        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            int j = size - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return true;
        } else {
            return false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (nextPermutation(nums)) {
            ans.push_back(nums);
        }
        return ans;
    }
};