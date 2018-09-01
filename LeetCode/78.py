class Solution:
    def dfs(self, nums, index, nums_len, ret, cur):
        if index == nums_len:
            ret.append([item for item in cur])
            return
        cur.append(nums[index])
        self.dfs(nums, index+1, nums_len, ret, cur)
        cur.pop(-1)
        self.dfs(nums, index+1, nums_len, ret, cur)
        
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        cur = []
        ret = []
        nums_len = len(nums)
        self.dfs(nums, 0, nums_len, ret, cur)
        return ret
