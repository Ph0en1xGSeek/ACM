class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        
        arr = [0] * n
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    arr[j] = grid[i][j]
                elif i == 0:
                    arr[j] = arr[j-1] + grid[i][j]
                elif j == 0:
                    arr[j] = arr[j] + grid[i][j]
                else:
                    arr[j] = grid[i][j] + min(arr[j], arr[j-1])
        return arr[-1]