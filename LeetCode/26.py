class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        i = 0
        while i < length-1:
            if nums[i] == nums[i+1]:
                nums.pop(i+1)
                length -= 1
                i -= 1
            i += 1
        return len(nums)