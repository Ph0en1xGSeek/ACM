class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n % 2 == 0:
            half = n // 2
        else:
            half = n // 2 + 1
        cnt = {}
        for i in range(n):
            if not cnt.has_key(nums[i]):
                cnt[nums[i]] = 1
            else:
                cnt[nums[i]] += 1
            if cnt[nums[i]] >= half:
                return nums[i]
            
            