class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        target = len(nums)
        cur = 0;
        for i in range(target):
            if i > cur:
                return False
            cur = max(cur, i + nums[i])
        return True