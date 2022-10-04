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