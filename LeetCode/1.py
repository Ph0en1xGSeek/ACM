class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        import numpy as np
        for i in range(len(nums)):
            if target-nums[i] in nums[i+1:]:
                return [i, nums.index(target-nums[i], i+1)]
