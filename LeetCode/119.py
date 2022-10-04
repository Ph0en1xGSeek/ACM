class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        arr = []
        arr.append([0])
        arr.append([0])
        for i in range(rowIndex+1):
            
            arr[i%2] = [0]*(i+1)
            for j in range(i+1):
                if j == 0 or j == i:
                    arr[i%2][j] = 1
                else:
                    arr[i%2][j] = arr[1-i%2][j-1] + arr[1-i%2][j]
        return arr[rowIndex%2]