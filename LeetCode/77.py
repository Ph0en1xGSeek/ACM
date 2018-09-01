class Solution:
    def dfs(self, n, k, ret, cur):
        if k == 0:
            ret.append([item for item in cur])
            return
        if k > n:
            return
        cur.append(n)
        self.dfs(n-1, k-1, ret, cur)
        cur.pop(-1)
        self.dfs(n-1, k, ret, cur)
        
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ret = []
        cur = []
        self.dfs(n, k, ret, cur)
        return ret
