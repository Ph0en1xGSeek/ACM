class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = 0
        l = 0
        r = 0
        next_r = 0
        while r < len(nums) - 1:
            for i in range(l, r+1):
                next_r = max(next_r, i+nums[i])
            l = r + 1
            r = next_r
            k += 1
        return k