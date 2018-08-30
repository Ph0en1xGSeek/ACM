class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        arr = []
        for i in range(m):
            arr.append([1]*n)
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    arr[i][j] = 0
                elif i == 0 and j == 0:
                    continue
                elif i == 0:
                    arr[i][j] = arr[i][j-1]
                elif j== 0:
                    arr[i][j] = arr[i-1][j]
                else:
                    arr[i][j] = arr[i-1][j] + arr[i][j-1]
        return arr[m-1][n-1]