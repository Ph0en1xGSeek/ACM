class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return None
        nums.sort()
        cur = nums[0] + nums[1] + nums[2]
        dif = abs(target - nums[0] - nums[1] - nums[2])
        for i in range(len(nums) - 2):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                if nums[l] + nums[r] + nums[i] == target:
                    return target
                if abs(target - nums[i] - nums[l] - nums[r]) < dif:
                    dif = abs(target - nums[i] - nums[l] - nums[r])
                    cur = nums[i] + nums[l] + nums[r]
                if nums[l] + nums[r] + nums[i] < target:
                    l += 1
                else:
                    r -= 1
        return cur