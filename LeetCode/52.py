class Solution:
    def dfs(self, cur, n, col, leading, vice, ans):
        if cur == n:
            ans[0] += 1
            return ans
        for i in range(n):
            if col[i] == False and leading[cur-i+n-1] == False and vice[cur+i] == False:
                col[i] = True
                leading[cur-i+n-1] = True
                vice[cur+i] = True
                self.dfs(cur+1, n, col, leading, vice, ans)
                col[i] = False
                leading[cur-i+n-1] = False
                vice[cur+i] = False
        return ans
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        col = [False]*n
        leading = [False]*(n*2-1)
        vice = [False]*(n*2-1)
        ans = [0]
        self.dfs(0, n, col, leading, vice, ans)
        return ans[0]