class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] < nums[right]){
            return nums[left];
        }
        while(left <= right && nums[left] >= nums[right]){
            int mid = (left + right) >> 1;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else if(nums[mid] < nums[left]){
                right = mid;
            }else if(nums[mid] == nums[right]){
                right--;
            }else if(nums[mid] == nums[left]){
                left++;
            }
        }
        return nums[left];
    }
};