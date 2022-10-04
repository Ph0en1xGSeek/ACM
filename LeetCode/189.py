class Solution(object):
    def reverse(self, nums, l, r):
        while(l < r):
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
    
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0 or k == 0:
            return
        if k > len(nums):
            k %= len(nums)
        nums.reverse()
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, len(nums)-1)