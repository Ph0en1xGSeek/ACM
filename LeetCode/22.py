class Solution(object):
    def dfs(self, res, n, char, cur, left):
        if cur == 2 * n:
            res.append(char)
            return
        if 2*n-cur > left:
            self.dfs(res, n, char+'(', cur+1, left+1)
        if left > 0:
            self.dfs(res, n, char+')', cur+1, left-1)
    
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        char = ''
        self.dfs(res, n, char, 0, 0)
        return res