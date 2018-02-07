class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        a = abs(dividend)
        b = abs(divisor)
        arr = []
        while(b <= a):
            arr.append(b)
            b <<= 1
        sum = 0
        ret = 0
        for i in range(len(arr)-1, -1, -1):
            if sum + arr[i] <= a:
                sum += arr[i]
                ret += (1<<i)
        if(((dividend > 0) and (divisor < 0)) or ((dividend < 0) and (divisor > 0))):
            return -ret
        else:
            return ret