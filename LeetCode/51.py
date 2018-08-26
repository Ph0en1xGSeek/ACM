class Solution:
    def dfs(self, cur, n, board, col, leading, vice, ans):
        if cur == n:
            curBoard = [''.join(item) for item in board]
            ans.append(curBoard)
        for i in range(n):
            if col[i] == False and leading[cur-i+n-1] == False and vice[cur+i] == False:
                board[cur][i] = 'Q'
                col[i] = True
                leading[cur-i+n-1] = True
                vice[cur+i] = True
                self.dfs(cur+1, n, board, col, leading, vice, ans)
                col[i] = False
                leading[cur-i+n-1] = False
                vice[cur+i] = False
                board[cur][i] = '.'

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = [['.']*n for _ in range(n)]
        col = [False]*n
        leading = [False]*(n*2-1)
        vice = [False]*(n*2-1)
        ans = []
        self.dfs(0, n, board, col, leading, vice, ans)
        return ans