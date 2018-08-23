class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 1
        for i in range(length):
            while nums[i] > 0 and nums[i] <= length and nums[i] != i+1 and nums[i] != nums[nums[i]-1]:
                tmp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = tmp
        
        for i in range(length):
            if nums[i] != i+1:
                return i+1
        return length+1