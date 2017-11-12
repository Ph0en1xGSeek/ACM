class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        import math
        return int(math.floor(x ** 0.5))