class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
             
        ret = []
        for _ in range(n):
            ret.append([0]*n)
        cnt = 1
        for k in range(n // 2):
            for i in range(k, n-1-k):
                ret[k][i] = cnt
                cnt += 1
            for i in range(k, n-1-k):
                ret[i][n-1-k] = cnt
                cnt += 1
            for i in range(n-1-k, k, -1):
                ret[n-1-k][i] = cnt
                cnt += 1
            for i in range(n-1-k, k, -1):
                ret[i][k] = cnt
                cnt += 1
                
        if n % 2 == 1:
            ret[n//2][n//2] = cnt
        return ret
        
