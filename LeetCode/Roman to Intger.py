class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        arr = []
        for ch in s:
            if ch == 'I':
                num = 1
            elif ch == 'V':
                num = 5
            elif ch == 'X':
                num = 10
            elif ch == 'L':
                num = 50
            elif ch == 'C':
                num = 100
            elif ch == 'D':
                num = 500
            elif ch == 'M':
                num = 1000
            
            if len(arr) == 0:
                arr.append(num)
            elif arr[-1] < num:
                arr[-1] = -arr[-1]
                arr.append(num)
            elif arr[-1] >= num:
                arr.append(num)
        return sum(arr)