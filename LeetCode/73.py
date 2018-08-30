class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        rowflag = False
        colflag = False
        for i in range(len(matrix[0])):
            if matrix[0][i] == 0:
                rowflag = True
                break
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                colflag = True
                break
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[0][j] = matrix[i][0] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        if rowflag:
            for i in range(len(matrix[0])):
                matrix[0][i] = 0
        if colflag:
            for i in range(len(matrix)):
                matrix[i][0] = 0