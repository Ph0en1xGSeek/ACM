class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0:
            return True
        i = 0
        j = len(s)-1
        while i < j:
            if not s[i].isalpha() and not s[i].isdigit():
                i += 1
            elif s[j].isalpha() == False and not s[j].isdigit():
                j -= 1
            elif s[i].lower() == s[j].lower():
                i += 1
                j -= 1
            else:
                return False
        return True