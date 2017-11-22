class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        arr = []
        for i in range(numRows):
            arr.append([0]*(i+1))
            for j in range(i+1):
                if j == 0 or j == i:
                    arr[i][j] = 1
                else:
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j]
        return arr
            