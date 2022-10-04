class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        flag = False
        if(n < 0):
            n = -n
            flag = True
        
        res = 1.0
        while(n > 0):
            if(n & 1 == 1):
                res *= x
            x *= x
            n >>= 1

        if flag:
            res = 1.0 / res
        
        return res