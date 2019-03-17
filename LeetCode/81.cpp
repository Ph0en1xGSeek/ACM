class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return false;
        }
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(nums[mid] == target) {
                return true;
            }else if(nums[mid] == nums[left]){
                left++;
                continue;
            }else if(nums[mid] > nums[left]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[right] >= target && nums[mid] < target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};