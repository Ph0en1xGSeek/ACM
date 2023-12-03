class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1, -1]
        l = 0
        r = len(nums)-1
        # left most
        while l <= r:
            mid = (l+r) // 2
            if nums[mid] >= target:
                r = mid-1
            else:
                l = mid+1
        if l >= len(nums) or nums[l] != target:
            return [-1, -1]
        left = l

        l = 0
        r = len(nums)-1
        # right most
        while l <= r:
            mid = (l+r) // 2
            if nums[mid] > target:
                r = mid-1
            else:
                l = mid+1
        right = r
        return [left, right]


class Solution {
public:

    int lower_bound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int lower = lower_bound(nums, target);
        if (lower >= size || nums[lower] != target) {
            return {-1, -1};
        }
        int upper = upper_bound(nums, target);
        return {lower, upper - 1};
    }
};