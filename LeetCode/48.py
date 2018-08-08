class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        matrix_len = len(matrix)
        for i in range(matrix_len // 2):
            for j in range(matrix_len - matrix_len // 2):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[matrix_len - j - 1][i]
                matrix[matrix_len - j - 1][i] = matrix[matrix_len - i - 1][matrix_len - j - 1]
                matrix[matrix_len - i - 1][matrix_len - j - 1] = matrix[j][matrix_len - i - 1]
                matrix[j][matrix_len - i - 1] = tmp