class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tot = 0
        for i in range(len(nums)):
            tot ^= nums[i]
        return tot