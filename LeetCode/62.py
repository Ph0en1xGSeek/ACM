class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        arr = []
        for i in range(m):
            arr.append([1]*n)
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    continue
                else:
                    arr[i][j] = arr[i-1][j] + arr[i][j-1]
        return arr[m-1][n-1]