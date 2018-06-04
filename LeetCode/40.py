class Solution:
    def dfs(self, target, index, currentArr, result, candidates):
        if target == 0:
            result.append(currentArr)
            return
        if target < 0:
            return
        prev = -1
        for i in range(index, len(candidates)):
            if prev == candidates[i]:
                continue
            self.dfs(target-candidates[i], i+1, currentArr+[candidates[i]], result, candidates)
            prev = candidates[i]

    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(candidates) == 0:
            return []
        result = []
        candidates.sort()
        self.dfs(target, 0, [], result, candidates)
        return result