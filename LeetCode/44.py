class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s_back = None
        p_back = None
        s_pos = p_pos = 0
        s_length = len(s)
        p_length = len(p)
        while s_pos != s_length:
            if p_pos != p_length and p[p_pos] == '*':
                s_back = s_pos
                p_pos += 1
                p_back = p_pos
            elif p_pos != p_length and (s[s_pos] == p[p_pos] or p[p_pos] == '?'):
                s_pos += 1
                p_pos += 1
            elif p_back != None:
                s_back  += 1
                s_pos = s_back
                p_pos = p_back
            else:
                return False

        while p_pos != p_length:
            if p[p_pos] != '*':
                return False
            p_pos += 1
        
        return True

