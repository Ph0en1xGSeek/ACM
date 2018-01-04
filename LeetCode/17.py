class Solution(object):
    wlist = [' ', '*', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
    def dfs(self, digits, cur, res, num):
        if num == len(digits):
            res.append(cur)
            return
        for i in range(len(self.wlist[ord(digits[num])-48])):
            self.dfs(digits, cur+self.wlist[ord(digits[num])-48][i], res, num+1)
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if len(digits) > 0:
            self.dfs(digits, '', res, 0)
        return res