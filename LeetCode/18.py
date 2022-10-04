class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        nums.sort()
        res = []
        for i in range(length-3):
            if i != 0 and nums[i] == nums[i-1]:
                i += 1
                continue
            for j in range(i+1, length-2):
                if j != i+1 and nums[j] == nums[j-1]:
                    j += 1
                    continue
                cur = nums[i] + nums[j]
                k = j+1
                l = length-1
                while k < l:
                    if cur + nums[k] + nums[l] < target:
                        k += 1
                    elif cur + nums[k] + nums[l] > target:
                        l -= 1
                    else:
                        res.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1
                        l -= 1
                        while k < l and nums[k] == nums[k-1]:
                            k += 1
                        while k < l and nums[l] == nums[l+1]:
                            l -= 1
        return res
                    