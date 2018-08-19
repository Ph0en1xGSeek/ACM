class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        num_r = len(matrix)
        if num_r == 0:
            return []
        num_c = len(matrix[0])
        if num_c == 0:
            return []
        min_num = min(num_r, num_c)

        
        ret = []
        for k in range(min_num // 2):
            for i in range(k, num_c-1-k):
                ret.append(matrix[k][i])
            for i in range(k, num_r-1-k):
                ret.append(matrix[i][num_c-1-k])
            for i in range(num_c-1-k, k, -1):
                ret.append(matrix[num_r-1-k][i])
            for i in range(num_r-1-k, k, -1):
                ret.append(matrix[i][k])
                
        if min_num % 2 == 1:
            if min_num == num_r:
                for i in range(min_num // 2, num_c-min_num//2):
                    ret.append(matrix[min_num//2][i])
            else:
                for i in range(min_num // 2, num_r-min_num//2):
                    ret.append(matrix[i][min_num//2])
        return ret
        