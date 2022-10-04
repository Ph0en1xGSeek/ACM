class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        for i in range(len(s)):
            tmp = ord(s[i]) - ord('A') + 1
            res = res * 26 + tmp
        return res