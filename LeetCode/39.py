class Solution:
    def dfs(self, target, index, currentArr, result, candidates):
        if target == 0:
            result.append(currentArr)
            return
        if target < 0:
            return
        for i in range(index, len(candidates)):
            self.dfs(target-candidates[i], i, currentArr+[candidates[i]], result, candidates)

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(candidates) == 0:
            return []
        result = []
        self.dfs(target, 0, [], result, candidates)
        return result
        