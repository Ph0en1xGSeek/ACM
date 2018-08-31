class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        l = 0
        r = len(matrix) - 1
        if r < 0:
            return False
        if len(matrix[0]) == 0:
            return False
        while l <= r:
            mid = (l+r) >> 1
            if matrix[mid][0] > target:
                r = mid-1
            else:
                l = mid+1
        
        if r < 0:
            return False
        row = r
        l = 0
        r = len(matrix[row]) - 1
        while l <= r:
            mid = (l+r) >> 1
            if matrix[row][mid] > target:
                r = mid-1
            else:
                l = mid+1
        if r < 0 or matrix[row][r] != target:
            return False
        else:
            return True
