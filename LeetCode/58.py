class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        str = s.lstrip().rstrip().split(' ')[-1]
        return len(str)