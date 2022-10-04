class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        import re
        minus = 1
        if len(str) == 0:
            return 0
        str = str.strip()
        i = 0
        while i < len(str):
            if i == 0 and (str[i] == '-' or str[i] == '+') and minus == 1:
                minus = -1
            elif str[i] not in ['0','1','2','3','4','5','6','7','8','9']:
                break
            i += 1
        if i == 0 or (i == 1 and minus == -1):
            return 0
        res = int(str[0:i])
        res = min(res, 2147483647)
        res = max(res, -2147483648)
        return res