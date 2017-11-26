class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = ''
        while n > 0:
            n -= 1
            tmp = n % 26
            n /= 26
            res = chr(tmp + ord('A')) + res
        return res