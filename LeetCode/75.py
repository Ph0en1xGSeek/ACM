class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums_len = len(nums)
        if nums_len == 0:
            return
        left = 0
        right = nums_len - 1
        index = 0
        while index <= right:
            if nums[index] == 1:
                index += 1
            elif nums[index] == 0:
                tmp = nums[index]
                nums[index] = nums[left]
                nums[left] = tmp
                left += 1
                index += 1
            elif nums[index] == 2:
                tmp = nums[index]
                nums[index] = nums[right]
                nums[right] = tmp
                right -= 1
