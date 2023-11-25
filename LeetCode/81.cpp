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


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return false;
        }
        if (size == 1) {
            return nums[0] == target;
        }
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};