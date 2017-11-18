class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longest = id = bounder = 0
        pos = 1
        str = '$'
        str += '#'
        for i in range(len(s)):
            str += (s[i] + '#')
        str += '^'
        p = [0] * len(str)
        for i in range(1, len(str)-1):
            if i < bounder:
                p[i] = min(p[2*id - i], bounder - i)
            else:
                p[i] = 1
            
            while str[i+p[i]] == str[i-p[i]]:
                p[i] += 1
            if i + p[i] > bounder:
                bounder = i + p[i]
                id = i
            if p[i] > longest:
                longest = p[i]
                pos = i
        
        if pos % 2 == 0:
            return s[(pos-2)//2 - (longest-1)//2 : (pos-2)//2 + (longest-1)//2 + 1]
        else:
            return s[pos//2 - (longest-1)//2: pos//2 + (longest-1)//2]
         