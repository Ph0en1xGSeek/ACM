class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1
        if x < 0:
            x = -x
            sign = -1
        arr = []
        while(x > 0):
            arr.append(x % 10)
            x //= 10
        ans = 0
        for num in arr:
            ans *= 10
            ans += num
        if ans > pow(2, 31):
            ans = 0
        ans *= sign
        return ans