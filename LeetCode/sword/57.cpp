class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0;
        int r = size - 1;
        vector<int> arr(2, 0);
        while(l < r) {
            if(nums[l] + nums[r] < target) {
                ++l;
            }else if(nums[l] + nums[r] > target) {
                --r;
            }else {
                arr[0] = nums[l];
                arr[1] = nums[r];
                break;
            }
        }
        return arr;
    }
};